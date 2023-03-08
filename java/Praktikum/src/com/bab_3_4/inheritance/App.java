package com.bab_3_4.inheritance;

public class App {
  public static void main(String[] args) {
    Zombie jombi = new Zombie("yuda", 100);
    Komang komang = new Komang("komang", 80);

    jombi.serang();
    komang.serang();
  }
}
