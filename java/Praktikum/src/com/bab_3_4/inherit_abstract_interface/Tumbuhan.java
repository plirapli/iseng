package com.bab_3_4.inherit_abstract_interface;

public class Tumbuhan extends MakhlukHidup {
  Tumbuhan(String nama) {
    super(nama, 0, false);
  }

  public void bernafas() {
    System.out.println(nama + " bernafas dg menghirup CO2");
  }

  public static void main(String[] args) {
    Tumbuhan t = new Tumbuhan("Bayam");
    t.status();
    t.bernafas();
  }
}
