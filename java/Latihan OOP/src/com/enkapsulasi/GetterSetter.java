package com.enkapsulasi;

class Data {
  public int intPublic;
  private int intPrivate;
  private double doublePrivate;

  public Data() {
    this.intPublic = 0;
    this.intPrivate = 0;
  }

  // Getter intPrivate
  public int getIntPrivate() {
    return this.intPrivate;
  }

  // Setter doublePrivate
  public void setDoublePrivate(Double doublePrivate) {
    this.doublePrivate = doublePrivate;
  }
}

class Lingkaran {
  private double diameter;

  Lingkaran(double diameter) {
    this.diameter = diameter;
  }

  // Setter
  public void setR(double r) {
    this.diameter = r * 2;
  }

  // Getter
  public double getR() {
    return this.diameter / 2;
  }

  // Getter
  public double getLuas() {
    return 3.14 * getR() * getR();
  }
}

public class GetterSetter {
  public static void main(String[] args) {
    Data object = new Data();

    // R/W Public
    object.intPublic = 10; // Write
    System.out.println(object.intPublic); // Read

    // Read Only (Getter)
    int angka = object.getIntPrivate();
    System.out.println(angka);

    // Write Only (Setter)
    object.setDoublePrivate(20.5);

    // R/W (Setter & Getter)
    Lingkaran object2 = new Lingkaran(7);
    System.out.println("r: " + object2.getR());
    object2.setR(14);
    System.out.println("r: " + object2.getR());
    System.out.println("Luas: " + object2.getLuas());
  }
}
