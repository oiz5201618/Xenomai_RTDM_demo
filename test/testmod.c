#include <linux/kernel.h>
#include <linux/init.h>
#include <rtdm/driver.h>

#define TASK_PRIO 99
#define TASK_PERIOD 1*s

#define s 1000000000 // 1 s = 10^9 ns

rtdm_task_t task;

void* repeat_printk(void) {

        int err;

        while(1) {
                err = rtdm_task_wait_period(NULL);
                if(err < 0) {
                        rtdm_printk("<6> wait_period failed\n");
                        break;
                }
                rtdm_printk("<6> Hello bitch kernel. <3 \n");
        }

}

int __init test_init(void) {

	int err;

	err = rtdm_task_init(&task, "rt_task", repeat_printk, NULL, TASK_PRIO, TASK_PERIOD);
	if(err < 0)
		rtdm_printk("<6> rtdm_task_init failed\n");
	
	err = rtdm_task_set_period(&task, 0, TASK_PERIOD);
	if(err < 0)
		rtdm_printk("<6> rtdm_task_set_period failed\n");

	return err;

}

void __exit test_exit(void) {

	rtdm_task_destroy(&task);
	printk("<6> Good bye bitch kernel. <3 \n");

}

MODULE_LICENSE("GPL");

module_init(test_init);
module_exit(test_exit);
