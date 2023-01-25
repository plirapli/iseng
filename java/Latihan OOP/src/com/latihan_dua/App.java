package com.latihan_dua;

class Player {
  private String name;
  private int level;

  private int baseHealth;
  private int baseDamage;

  private int incrementHealth;
  private int incrementDamage;

  private Armor armor;
  private Weapon weapon;

  public Player(String name) {
    this.name = name;
    this.level = 1;

    this.baseHealth = 100;
    this.baseDamage = 15;

    this.incrementHealth = 20;
    this.incrementDamage = 5;
  }

  public void display() {
    System.out.println("Player: " + this.name);
    System.out.println("Level: " + this.level);
    System.out.println("Max Health: " + this.maxHealth());
    System.out.println("Damage: " + this.getTotalDamage());
    System.out.println();
  }

  public void setArmor(Armor armor) {
    this.armor = armor;
  }

  public void setWeapon(Weapon weapon) {
    this.weapon = weapon;
  }

  public void levelUp() {
    this.level++;
  }

  public int maxHealth() {
    return this.baseHealth + this.level * this.incrementHealth + this.armor.getAddHealth();
  }

  public int getTotalDamage() {
    return this.baseDamage + this.level * this.incrementDamage + this.weapon.getWeaponDamage();
  }
}

class Armor {
  private String name;
  private int defense;
  private int health;

  public Armor(String name, int defense, int health) {
    this.name = name;
    this.defense = defense;
    this.health = health;
  }

  public int getAddHealth() {
    return this.defense * 10 + this.health;
  }
}

class Weapon {
  private String name;
  private int damage;

  public Weapon(String name, int dmg) {
    this.name = name;
    this.damage = dmg;
  }

  public int getWeaponDamage() {
    return this.damage;
  }
}

public class App {
  public static void main(String[] args) {
    Player player1 = new Player("Seva");
    Armor armor1 = new Armor("Copper Armor", 5, 100);
    Weapon weapon1 = new Weapon("Copper Sword", 10);

    Player player2 = new Player("Hekal");
    Armor armor2 = new Armor("Tin Armor", 6, 100);
    Weapon weapon2 = new Weapon("Tin Sword", 11);

    player1.setWeapon(weapon1);
    player1.setArmor(armor1);
    player1.display();

    player2.setWeapon(weapon2);
    player2.setArmor(armor2);
    player2.display();

    player1.levelUp();
    player1.display();

    player2.levelUp();
    player2.display();
  }
}
