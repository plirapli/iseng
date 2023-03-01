package com.bab_3_4.exception;

import java.io.*;

class Input {
  public static int bacaData() {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int angka = 0;

    try {
      String input = br.readLine();
      angka = Integer.parseInt(input);
    } catch (Exception err) {
      System.out.println("Input salah. Inisialisasi dengan nilai! " + angka);
    } finally {
      return angka;
    }
  }
}

public class TesInputBuffer {
  public static void main(String[] args) {
    System.out.print("Masukkan angka: ");
    int i = Input.bacaData();

    System.out.println("Angka yang Anda masukkan adalah " + i);
  }
}
