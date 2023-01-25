package com.latihan_dua;

class Player {
  private String name;
  private int level;
  private int baseHealth, baseDamage;
  private int incrementHealth, incrementDamage;
  private int totalDamage;
  private Boolean isAlive;

  // Object member
  private Armor armor;
  private Weapon weapon;

  public Player(String name) {
    this.name = name;
    this.level = 1;

    this.baseHealth = 100;
    this.baseDamage = 15;

    this.incrementHealth = 20;
    this.incrementDamage = 5;

    this.isAlive = true;
  }

  public String getName() {
    return this.name;
  }

  public int getHealth() {
    return this.maxHealth() - this.totalDamage;
  }

  public void display() {
    System.out.println("Player: " + this.name);
    System.out.println("Level: " + this.level);
    System.out.println("Health: " + this.getHealth() + "/" + this.maxHealth());
    System.out.println("Damage: " + this.getDamage());
    System.out.println("Alive: " + this.isAlive);
    System.out.println();
  }

  public void attack(Player opponent) {
    // Hitung damage
    int damage = this.getDamage();

    // Print event
    System.out.println(
        this.name + " is attacking " + opponent.getName() + "! (" + damage + " dps)");

    // Opponent defend
    opponent.defend(damage);

    this.levelUp(); // Leveling up
  }

  public void defend(int damageTaken) {
    int armorDefense = this.armor.getArmorDefense();

    if (damageTaken > armorDefense) {
      damageTaken -= armorDefense;
    } else {
      damageTaken = 0;
    }

    System.out.println(this.name + " Defense: " + this.armor.getArmorDefense());
    System.out.println("Damage Taken: " + damageTaken + "\n");

    this.totalDamage += damageTaken;

    // Check is alive
    if (this.getHealth() <= 0) {
      this.isAlive = false;
      this.totalDamage = this.maxHealth();
    }

    this.display();
  }

  private void levelUp() {
    this.level++;
  }

  private int maxHealth() {
    return this.baseHealth + this.level * this.incrementHealth + this.armor.getAddHealth();
  }

  private int getDamage() {
    return this.baseDamage + this.level * this.incrementDamage + this.weapon.getWeaponDamage();
  }

  public void setArmor(Armor armor) {
    this.armor = armor;
  }

  public void setWeapon(Weapon weapon) {
    this.weapon = weapon;
  }
}

class Armor {
  private String name;
  private int defense, health;

  public Armor(String name, int defense, int health) {
    this.name = name;
    this.defense = defense;
    this.health = health;
  }

  public int getAddHealth() {
    return this.defense * 10 + this.health;
  }

  public int getArmorDefense() {
    return this.defense * 2;
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

    // player1.levelUp();
    // player1.display();

    // player2.levelUp();
    // player2.display();

    player1.attack(player2);
    player2.attack(player1);
    player2.attack(player1);
  }
}
