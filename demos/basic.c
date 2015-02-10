#include <state.h>
#include <stdio.h>

int a(void *p){
  static int counter=0;
  counter+=1;
  printf("a: %d\n",counter);
  return counter;
}

int b(void *p){
  printf("b\n");
  return 0;
}

int main(){
  struct StateMachine *machine;
  machine=state_newmachine();
  state_add_transition(machine,a,1,b);
  state_add_transition(machine,b,0,a);
  state_add_transition(machine,a,2,NULL);
  state_start(machine,a,NULL);
  state_free(machine);
}
