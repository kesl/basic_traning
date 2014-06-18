#include <linux/io.h>
#include <linux/ioport.h>
#include <linux/mm.h>
#include <linux/interrupt.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/kfifo.h>
#include <linux/fs.h>
#include <linux/poll.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/miscdevice.h>
#include <linux/serial_reg.h>
#include <linux/cdev.h>
#include <asm/apic.h>

static struct miscdevice misc_loop_drv_dev = {
    .minor  = MISC_DYNAMIC_MINOR,
    .name   = KBUILD_MODNAME,
};

/*
 * Initialization and cleanup section
 */

static void misc_loop_drv_cleanup(void)
{
    pr_info("MODNAME=%s cleanup\n", KBUILD_MODNAME);
    if (misc_loop_drv_dev.this_device)
        misc_deregister(&misc_loop_drv_dev);
}

static __devinit int misc_loop_drv_init(void)
{
    int ret = 0;

    pr_info("MODNAME=%s  init\n", KBUILD_MODNAME);

    ret = misc_register(&misc_loop_drv_dev);
    if (ret < 0) {
        pr_err("misc_register failed\n");
        goto exit;
    }
    pr_debug("misc_loop_drv_dev.minor=%d\n", misc_loop_drv_dev.minor);

exit:
    pr_debug("ret=%d\n", ret);
    if (ret < 0)
        misc_loop_drv_cleanup();
    return ret;
}

module_init(misc_loop_drv_init);
module_exit(misc_loop_drv_cleanup);

MODULE_DESCRIPTION("Simple misc device driver sample");
MODULE_AUTHOR("Constantine Shulyupin <const@makelinux.net>");
MODULE_AUTHOR("Joohyun Kyong <joohyun0115@gmail.com>");
MODULE_LICENSE("GPL");
