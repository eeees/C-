package com.example.test.Database;

import android.arch.persistence.room.Database;
import android.arch.persistence.room.Room;
import android.arch.persistence.room.RoomDatabase;
import android.content.Context;
import android.os.AsyncTask;


@Database(entities = {Users.class}, version =  1)
public abstract class UsersDatabase extends RoomDatabase {
    //데이터베이스를 매번 생성하는건 리소스를 많이사용하므로 싱글톤이 권장된다고한다.
    private static UsersDatabase INSTANCE;

    public abstract Daos mDao();

    //디비객체생성 가져오기
    public static UsersDatabase getAppDatabase(Context context){
        if(INSTANCE == null){
            INSTANCE = Room.databaseBuilder(context, UsersDatabase.class , "eggplant")
                    .fallbackToDestructiveMigration()
                    .build();

        }
        return  INSTANCE;
    }

    //디비객체제거
    public static void destroyInstance() {
        INSTANCE = null;
    }
}