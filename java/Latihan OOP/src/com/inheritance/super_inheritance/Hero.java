package com.inheritance.super_inheritance;

public class Hero {
  String name;

  void display() {
    System.out.println("Hero: " + this.name);
    System.out.println();
  }

  void dummyMethod() {
    System.out.println("Ini adalah method di Super Class");
  }
}
