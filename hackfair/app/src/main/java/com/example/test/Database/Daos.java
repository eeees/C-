package com.example.test.Database;

import android.arch.lifecycle.LiveData;
import android.arch.persistence.room.Dao;
import android.arch.persistence.room.Delete;
import android.arch.persistence.room.Insert;
import android.arch.persistence.room.Query;

import com.example.test.Database.Users;

import java.util.List;

@Dao
public interface Daos {


    @Query("SELECT * FROM Users")
    LiveData<List<Users>> loadAllUsers();

    @Query("SELECT password FROM Users WHERE id = :inputId")
    String loadPwById(String inputId);

    @Query("SELECT * FROM Users WHERE id = :ptId")
    Users[] isThereById(String ptId);

    // 제목을 넣으면 게시글을 찾아준다.
    @Query("SELECT contents FROM Users WHERE title = :inputTitle")
    String loadCntByTitle(String inputTitle);

    // 게시글 개수 출력
    @Query("SELECT count(*) FROM Users WHERE name = :input")
    Integer countPosts(String input);

    // 게시글 내용 받아오기
    @Query("SELECT contents FROM Users WHERE name = :input")
    String[] returnPosts(String input);

    // 게시글 제목 받아오기
    @Query("SELECT title FROM Users WHERE name = :input")
    String[] returnTitle(String input);


    @Insert
    void insertUser(Users... users);

    @Delete
    void deleteUsers(Users... users);
}

