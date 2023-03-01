package com.bab_3_4.exception;

class CobaException {
  public static void main(String[] args) {
    int nilai = 0;
    try {
      nilai = Integer.parseInt(args[0]);
      // dalam blok exception-handling
    } catch (Exception error) {
      System.out.println("Error: " + error);
    } finally {
      System.out.println("Nilai Anda: " + nilai);
    }
    System.out.println("Selesai..");
  }
}