package com.enkapsulasi_dua;

class Display {
  static String type = "Display";
  private String name;

  Display(String name) {
    this.name = name;
  }

  void setType(String type) {
    Display.type = type;
  }

  void show() {
    System.out.println("Display Name: " + this.name);
  }
}

public class StaticAttribute {
  public static void main(String[] args) {
    Display display1 = new Display("Monitor");
    display1.show();

    Display display2 = new Display("Smartphone");
    display2.show();

    // Change static var
    display1.setType("Tampilan");

    // Show static var
    System.out.println(display1.type);
    System.out.println(display2.type);
    System.out.println(Display.type);
  }
}
