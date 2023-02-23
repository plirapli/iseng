package com.pertemuan_1;

public class App {
  public static void main(String[] args) throws Exception {
    // Triangle
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 10; j++) {
        if (j < 4 - i || j > 4 + i)
          System.out.print("  ");
        else
          System.out.print("* ");
      }
      System.out.println();
    }
  }
}
