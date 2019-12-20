package com.example.test;

public class PersonItem {


    String name;
    int color;


    public String getName() { return name;}
    public int getColor() {return color;}



    public void setName(String name) {
        this.name = name;
    }

    public void setColor(int color) {
        this.color = color;
    }

    public PersonItem(String name, int color){
        this.name=name;
        this.color=color;
    }
}
