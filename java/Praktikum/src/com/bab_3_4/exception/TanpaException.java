package com.bab_3_4.exception;

class TanpaException {
  public static void main(String[] args) {
    int nilai = Integer.parseInt(args[0]);
    // statement diatas membutuhkan exception-handling

    System.out.println("Nilai yang dimasukkan: " + nilai);
  }
}