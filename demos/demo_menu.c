#include <state.h>
#include <stdio.h>

enum main_menu_values{
    main_OPTION,
    main_RUN,
    main_EXIT
};

int main_menu(void *p){
    int i;
    while(1){
        printf("choices are:\n");
        printf("1. options (set values)\n");
        printf("2. run\n");
        printf("3. exit\n");
        if (scanf("%d",&i)!=1) return main_EXIT;
        if (i==1) return main_OPTION;
        if (i==2) return main_RUN;
        if (i==3) return main_EXIT;
        printf("wrong choice...\n");

    }
}

enum option_values{
    option_BACK,
    option_EXIT
};

struct Job{
    int a;
    int b;
};

int option_menu(void *p){
    struct Job *j=p;
    int i;
    while(1){
        printf("options: \n");
        printf("1. set a value (%d)\n",j->a);
        printf("2. set b value (%d)\n",j->b);
        printf("3. back\n");
        printf("4. exit\n");
        if (scanf("%d",&i)!=1) return option_EXIT;
        if (i==1){
            printf("value? ");
            scanf("%d",&(j->a));
        }
        if (i==2){
            printf("value? ");
            scanf("%d",&(j->b));
        }
        if (i==3) return option_BACK;
        if (i==4) return option_EXIT;
        printf("wrong choice...\n");
    }
}

enum run_values{
    run_FINISH
};

int run(void *p){
    struct Job *j=p;
    printf("doing the job...\n");
    printf("%d + %d = %d \n",j->a,j->b,j->a+j->b);
    return run_FINISH;
}


int main(){
    struct Job job={2,3};
    struct StateMachine *machine;
    machine=state_newmachine();
    state_add_transition(machine,main_menu,  main_EXIT,   NULL);
    state_add_transition(machine,main_menu,  main_OPTION, option_menu);
    state_add_transition(machine,main_menu,  main_RUN,    run);
    state_add_transition(machine,option_menu,option_EXIT, NULL);
    state_add_transition(machine,option_menu,option_BACK, main_menu);
    state_add_transition(machine,run,        run_FINISH,  main_menu);
    state_start(machine,main_menu,&job);
    state_free(machine);
}
