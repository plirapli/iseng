package com.inheritance.subclass_constructor;

// Super class
class Hero {
  String name;

  // Constructor
  Hero(String name) {
    this.name = name;
  }

  void display() {
    System.out.println("Hero");
    System.out.println("Name: " + this.name);
    System.out.println();
  }
}
