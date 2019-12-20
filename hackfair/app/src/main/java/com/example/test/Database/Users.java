package com.example.test.Database;

import android.arch.persistence.room.ColumnInfo;
import android.arch.persistence.room.Entity;
import android.arch.persistence.room.PrimaryKey;
import android.support.annotation.NonNull;


@Entity
public class Users {
    @PrimaryKey(autoGenerate = true)
    @NonNull
    @ColumnInfo(name = "uid")
    private int mUid;
    public int getUid() {return this.mUid;}
    public void setUid(int uid) {this.mUid = uid;}

    @ColumnInfo(name = "name")
    private String mName;
    public String getName() {return this.mName;}
    //public void setName(String name) {}

    @ColumnInfo(name = "id")
    private String mId;
    public String getId() {return this.mId;}
    //public void setId(String id) {this.mId = id;}

    @ColumnInfo(name = "password")
    private String mPassword;
    public String getPassword() {return this.mPassword;}
    //public void setPassword(String password) {this.mPassword = password;}

    @ColumnInfo(name = "emgnum1")
    private String mEmgnum1;
    public String getEmgnum1() {return this.mEmgnum1;}
    //public void setEmgnum1(int emgnum1) {this.mEmgnum1 = emgnum1;}

    private String mEmgnum2;
    public String getEmgnum2() {return this.mEmgnum2;}
    //public void setEmgnum2(int emgnum2) {this.mEmgnum2 = emgnum2;}

    @ColumnInfo(name = "title")
    private String mTitle;
    public String getTitle() {return this.mTitle;}
    //public void setName(String name) {}

    @ColumnInfo(name = "contents")
    private String mContents;
    public String getContents() {return this.mContents;}
    //public void setId(String id) {this.mId = id;}

    //private int state;

    public Users(String name, String id, String password, String emgnum1, String emgnum2, String title, String contents) {
        //this.mUid = uid;
        this.mName = name;
        this.mId = id;
        this.mPassword = password;
        this.mEmgnum1 = emgnum1;
        this.mEmgnum2 = emgnum2;
        this.mTitle = title;
        this.mContents = contents;
       //this.state=0;
    }
}
