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

#include <linux/init.h>
#include <linux/kernel.h>


static struct miscdevice misc_loop_drv_dev = {
    .minor  = MISC_DYNAMIC_MINOR,
    .name   = KBUILD_MODNAME,
};

/*
 * Initialization and cleanup section
 */

static int hello_init(void)
{
	printk("hello Mijong\n");
	return 0;
}

static void hello_exit(void)
{
	printk("Goodbye Mijong\n");
}


module_init(hello_init);
module_exit(hello_exit);

MODULE_DESCRIPTION("Simple misc device driver sample");
MODULE_AUTHOR("Constantine Shulyupin <const@makelinux.net>");
MODULE_AUTHOR("Joohyun Kyong <joohyun0115@gmail.com>");
MODULE_LICENSE("GPL");
