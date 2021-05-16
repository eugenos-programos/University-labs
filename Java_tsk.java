package com.company;

import java.util.Scanner;

class cat{
    public String name;
    public int age;

    public cat(String name,int age){
        this.age = age;
        this.name = name;
    }

    public cat(){
        this.name = "Безымянный";
        this.age = -1;
    }
}

public class Main {

    public static void main(String[] args) {
        int age;
        String name;
        Scanner in = new Scanner(System.in);
        System.out.print("Input name:\n");
        name = in.nextLine();
        System.out.print("Input age:\n");
        age = in.nextInt();

        cat cat_object = new cat(name,age);
        System.out.println("name:" + cat_object.name);
        System.out.print("age:" + cat_object.age);

    }

}
