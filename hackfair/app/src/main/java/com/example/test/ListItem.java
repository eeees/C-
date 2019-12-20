package com.example.test;

public class ListItem {

    String name;
    int index;


    public String getName() {
        return name;
    }
    public int getIndex(){ return index;}

    public void setName(String name) {
        this.name = name;
    }
    public void setIndex(int index){this.index=index;}

    public ListItem( String name) {

        this.name = name;
        this.index=index;
    }
}