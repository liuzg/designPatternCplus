/*
 * doTest.cpp
 *
 *  Created on: 2018Äê2ÔÂ28ÈÕ
 *      Author: liu_z
 */
#include <iostream>
using namespace std;

//======= Pattern of Create =====//
void test_create_factory(void);
void test_create_factory_method(void);
void test_create_abstract_factory(void);
void test_create_singleton(void);
void test_create_singleton_subclass(void);
void test_create_prototype(void);
void test_create_builder(void);

//===== Patterns of behavior =====//
void test_behavior_strategy(void);
void test_behavior_strategy2(void);
void test_behavior_strategy3(void);
void test_behavior_template(void);
void test_behavior_Memento(void);
void test_behavior_Mediator(void);
void test_behavior_Reponsibility(void);
void test_behavior_observer(void);
void test_behavior_state(void);


//===== Patterns of structural =====//
void test_structural_adapter(void);
void test_structural_facade(void);
void test_structural_composite(void);
void test_structural_proxy(void);
void test_structural_flyweight(void);
void test_structural_bridge(void);
void test_structural_decorator(void);

int main(void)
{

	//======= Pattern of Create =====//
#if 0
	// Test Create_Factory
	cout << "Test Create_factory" << endl;
	test_create_factory();

	// Test Create_Factory_Method
	cout << "Test Create_Factory_Method" << endl;
	test_create_factory_method();

	// Test Create_abstract_factory
	cout << "Test Create_abstract_factory" << endl;
	test_create_abstract_factory();

	cout << "Test Create_Singleton" << endl;
	test_create_singleton();
	cout << "Test Create_Singleton with subclass" << endl;
	test_create_singleton_subclass();

	cout << "Test Create_Prototype" << endl;
	test_create_prototype();
	cout << "Test Create_Builder" << endl;
	test_create_builder();
#endif
#if 0
	//===== Patterns of behavior =====//
	cout << "Test behavior stratgy" << endl;
	test_behavior_strategy();
	cout << "Test behavior stratgy2" << endl;
	test_behavior_strategy2();
	cout << "Test behavior stratgy3" << endl;
	test_behavior_strategy3();

	cout << "Test behavior template" << endl;
	test_behavior_template();
	cout << "Test behavior Memento" << endl;
	test_behavior_Memento();
	cout << "Test behavior Mediator" << endl;
	test_behavior_Mediator();
	cout << "Test behavior responsibility" << endl;
	test_behavior_Reponsibility();
	cout << "Test behavior observer" << endl;
	test_behavior_observer();
#endif
	cout << "Test behavior state" << endl;
	test_behavior_state();

#if 0
	//===== Patterns of structural =====//
	cout << "Test structural adapter" << endl;
	test_structural_adapter();
	cout << "Test structural facase" << endl;
	test_structural_facade();
	cout << "Test structural composite" << endl;
	test_structural_composite();
	cout << "Test structural proxy" << endl;
	test_structural_proxy();
	cout << "Test structural flyweight" << endl;
	test_structural_flyweight();
	cout << "Test structural bridge" << endl;
	test_structural_bridge();
	cout << "Test structural decorator" << endl;
	test_structural_decorator();
#endif


	return 0;
}
