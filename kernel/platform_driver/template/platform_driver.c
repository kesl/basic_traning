#include <linux/module.h>
#include <linux/of.h>
#include <linux/platform_device.h>
#include <linux/of_platform.h>
#include <linux/mod_devicetable.h>
#include <linux/of_irq.h>


static __devinit int simple_platform_probe(struct platform_device *pdev)
{


    return 0;
}

static int __devexit simple_platform_plat_remove(struct platform_device *pdev)
{
_entry:
    return 0;
}

#ifdef CONFIG_PM

static int simple_platform_suspend(struct device *dev)
{
    return 0;
}

static int simple_platform_resume(struct device *dev)
{
    return 0;
}

static const struct dev_pm_ops simple_platform_pm = {
    .suspend = simple_platform_suspend,
    .resume  = simple_platform_resume,
};

#define simple_platform_pm_ops (&simple_platform_pm)
#else
#define simple_platform_pm_ops NULL
#endif

static struct platform_driver simple_platform_plat_driver = {


};

module_platform_driver(simple_platform_plat_driver);

MODULE_DESCRIPTION("platform device driver sample");
MODULE_AUTHOR("Constantine Shulyupin <const@makelinux.net>");
MODULE_AUTHOR("Joohyun Kyong <joohyun0115@gmail.com>");
MODULE_LICENSE("Dual BSD/GPL");
