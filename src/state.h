/* ------------------------------------------------- *
 *
 * this code is under MIT Licence
 * 
 * author: Julien Allali (allali.julien@gmail.com)
 *
 * Change log:
 * 02 11 2015: inital version
 *
 * ------------------------------------------------- */

/*! \file state.h
 * \brief state library api
 * 
 * The state library is really simple. First you must create a machine using the state_newmachine function. This will return an handler to an empty machine.
 * Then you can register any state and transition using state_add_transition function. A state is a pointer to a function, transition are associated to int. State return value are used to select the next state function that will be run. 
 * Finally, you can start your machine by giving the initial state function and a pointer that will be passed to all state function.
 * At last, release the resources associated to the machine using state_free.
 *
 * \include basic.c 
 * \example basic.c
 * \example demo_menu.c
 */

#ifndef STATE_H
#define STATE_H


/*! \brief handler to a state machine
 */
struct StateMachine;

/*! \brief Default type for a state function
 */
typedef int (*StateFunc)(void *data);

/*! \brief state_newmachine instanciate a new empty machine
 * \return NULL if error, a pointer that must be release with state_free
 */
struct StateMachine *state_newmachine();

/*! \brief state_free release resource of a machine allocated with state_newmachine
 * \param p a pointer returned by state_newmachine
 */
void state_free(struct StateMachine *p);

/*! \brief state_add_transition Add a new transition into the machine
 *
 * \param machine a pointer obtained with state_newmachine
 * \param from the current machine state
 * \param value the value return by from
 * \param to the state run after from, NULL if the machine must exit
 * \return 0 if no error, 1 if memory error, 2 if transition already in machine
 */
int state_add_transition(struct StateMachine *machine,StateFunc from, int value, StateFunc to);

/*! \brief state_start run a state machine
 * \param machine a pointer to the state machine
 * \param start the first state that will be run
 * \param data a pointer that will be passed to all states
 * \return the return value of the last state run
 */
int state_start(struct StateMachine *machine,StateFunc start, void *data);


#endif
