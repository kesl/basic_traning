#include <linux/module.h>
#include <linux/platform_device.h>

static struct resource platform_resource[] = {
    {
        .flags = IORESOURCE_IO,
        .start = 0x3f8,
        .end = 0x3ff,
    },
    {
        .flags = IORESOURCE_IRQ,
        .start = 4,
        .end = 4,
    },
    {
        .flags = IORESOURCE_MEM,
        .start = 0,
        .end = 0,
    },
};

static void sample_platform_release(struct device *dev)
{
}

static struct platform_device sample_platform_device = {
    .name   = "simple_platform_device_name",
    .resource   = platform_resource,
    .num_resources  = ARRAY_SIZE(platform_resource),
    .dev.platform_data = "test data",
    .dev.release    = sample_platform_release,
};

static int platform_device_init(void)
{
    return platform_device_register(&sample_platform_device);
}

static void platform_device_exit(void)
{
    platform_device_unregister(&sample_platform_device);
}

module_init(platform_device_init);
module_exit(platform_device_exit);

MODULE_DESCRIPTION("platform device driver sample");
MODULE_AUTHOR("Constantine Shulyupin <const@makelinux.net>");
MODULE_AUTHOR("Joohyun Kyong <joohyun0115@gmail.com>");
MODULE_LICENSE("GPL");
