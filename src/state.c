#include "state.h"
#include <stdlib.h>

/* ------------------------------------------------- *
 *
 * this code is under LIT Licence
 *
 * author: Julien Allali (allali.julien@gmail.com)
 *
 * Change log:
 * 02 11 2015: inital version
 *
 * ------------------------------------------------- */



struct State{
    StateFunc from,to;
    int value;
    struct State *next;
};

struct StateMachine{
    struct State *list;
};

struct State *state_new(StateFunc from,StateFunc to,int value){
    struct State *s=malloc(sizeof(*s));
    if (s==NULL) return NULL;
    s->from=from;
    s->to=to;
    s->value = value;
    s->next=NULL;
    return s;
}

struct StateMachine *state_newmachine(){
    struct StateMachine *p=malloc(sizeof(*p));
    if (p==NULL) return NULL;
    p->list=NULL;
    return p;
}

void state_free(struct StateMachine *p){
    struct State *t=p->list,*q;
    while(t!=NULL){
        q=t;
        t=t->next;
        free(q);
    }
    free(p);
}

int state_add_transition(struct StateMachine *machine,StateFunc from, int value, StateFunc to){
    struct State *newState=state_new(from,to,value);
    struct State *p,*q;
    if (newState==NULL) return 1;
    if (machine->list==NULL){
        machine->list=newState;
        return 0;
    }
    q=NULL;
    p=machine->list;
    while((p!=NULL) && (p->from<=from)&& (p->value<=value)){
        q=p;
        p=p->next;
    }
    if (q==NULL){
        if ((p->from==from) && (p->value==value) && (p->to==to)){
            free(newState);
            return 2;
        }
        newState->next=machine->list;
        machine->list=newState;
    } else {
        if ((q->from==from) && (q->value==value) && (q->to==to)){
            free(newState);
            return 2;
        }
        newState->next = p;
        q->next=newState;
    }
    return 0;
}

int state_start(struct StateMachine *machine,StateFunc start, void *data){
    int lastValue;
    struct State *p;
    while(1){
        lastValue=start(data);
        p=machine->list;
        while ((p!=NULL) && ((p->from!=start) || (p->value!=lastValue))){
            p=p->next;
        }
        if (p==NULL) return -1;
        if (p->to==NULL) return lastValue;
        start=p->to;
    }
}
