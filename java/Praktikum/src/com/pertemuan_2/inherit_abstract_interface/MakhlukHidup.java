package com.pertemuan_2.inherit_abstract_interface;

public abstract class MakhlukHidup {
  protected String nama;
  protected int jumlahkaki;
  protected boolean bisaTerbang;

  public MakhlukHidup(String nama, int jumlahkaki, boolean bisaTerbang) {
    this.nama = nama;
    this.jumlahkaki = jumlahkaki;
    this.bisaTerbang = bisaTerbang;
  }

  abstract void bernafas();

  public void status() {
    System.out.println("Nama: " + this.nama);
    System.out.println("Jumlah kaki: " + this.jumlahkaki);
    System.out.println("Bisa terbang? " + this.bisaTerbang);
  }
}
