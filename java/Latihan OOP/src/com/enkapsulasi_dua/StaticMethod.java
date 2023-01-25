package com.enkapsulasi_dua;

import java.util.ArrayList;

class Player {
  private static int numOfPlayer;
  private static ArrayList<String> nameList = new ArrayList<String>();

  private String name;

  Player(String name) {
    this.name = name;

    Player.numOfPlayer++;
    Player.nameList.add(this.name);
  }

  void show() {
    System.out.println("Player: " + this.name);
  }

  // Static Method
  static void showNumOfPlayer() {
    System.out.println("Number of Players: " + Player.numOfPlayer);
  }

  static ArrayList<String> getPlayers() {
    return Player.nameList;
  }
}

public class StaticMethod {
  public static void main(String[] args) {
    Player player1 = new Player("Seva");
    Player player2 = new Player("Hekal");
    Player player3 = new Player("Syaikul");
    Player player4 = new Player("Rafli");

    Player.showNumOfPlayer();
    System.out.println("Players: " + Player.getPlayers());
  }
}
