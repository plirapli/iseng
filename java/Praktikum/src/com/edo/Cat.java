package com.edo;

public class Cat {
  private String name;
  private int weight;
  private int age;

  public void setWeight(int newWeight) {
    weight = newWeight;
  }

  public void setAge(int age) {
    this.age = age;
  }

  public int getWeight() {
    return weight;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public int getAge() {
    return age;
  }
}
