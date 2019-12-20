package com.example.test;
import java.util.Date;

public class list_item2 {
    //추가한 변수
    private int profile_image;
    private String nickname;

    //알람에 따라 위급,, 그것도 넣어줘야할듯

    public list_item2(int profile_image, String nickname) {
        this.profile_image = profile_image;
        this.nickname = nickname;
    }

    public int getProfile_image() {
        return profile_image;
    }

    public void setProfile_image(int profile_image) {
        this.profile_image = profile_image;
    }

    public String getNickname() {
        return nickname;
    }


    public void setNickname(String nickname) {
        this.nickname = nickname;
    }


    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    private String content;
}