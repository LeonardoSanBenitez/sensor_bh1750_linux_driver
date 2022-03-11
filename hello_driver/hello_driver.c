#include <linux/init.h>      // macros to mark up functions e.g. __init
#include <linux/module.h>    // core header for loading LKMs
#include <linux/kernel.h>    // contains kernel types, macros, functions

MODULE_LICENSE("GPL");       // the license type (affects behavior)
MODULE_AUTHOR("Samir Bonho");  // The author visible with modinfo
MODULE_DESCRIPTION("Modulo diga oi pro boneco aqui."); // desc.
MODULE_VERSION("0.1");       // the version of the module

static char *name = "mundo"; 
module_param(name, charp, S_IRUGO); // S_IRUGO can be read/not changed
MODULE_PARM_DESC(name, "Variavel que ira aparecer em  /var/log/kern.log");


static int __init helloERPi_init(void) {
   printk(KERN_INFO "Um Oi %s do modulo tosco da RPi!\n", name);
   return 0;
}

static void __exit helloERPi_exit(void) {
   printk(KERN_INFO "Adeus %s !\n", name);
}


module_init(helloERPi_init);
module_exit(helloERPi_exit);
