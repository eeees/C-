package com.example.test;

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.util.ArrayList;


public class PostActivity_article extends AppCompatActivity {
    private final String TAG = "PostActivity_article";
    Button mAddFriendButton;
    TextView mWriter;
    String AddFriend;
    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_article);

        Intent intent = getIntent();
        ArrayList<String> ReceiveArr=intent.getStringArrayListExtra("ArrayList");
        Intent intent_list = getIntent();
        int index=intent.getIntExtra("Index",0);
        TextView textView=(TextView)findViewById(R.id.writer);
        textView.setText("정수림");
        TextView textView2=(TextView)findViewById(R.id.text);
        textView2.setText("조용하게 책읽으려고 하는데 주변에 조용한 카페 있을 까요?");
        TextView textView3=(TextView)findViewById(R.id.title);
        textView3.setText("테크노파크 주변에 조용한 카페있나요?");

        mAddFriendButton=(Button)findViewById(R.id.friend_add);
        mWriter=(TextView)findViewById(R.id.writer);
        AddFriend=(String)mWriter.getText();
        mAddFriendButton.setOnClickListener(new View.OnClickListener(){
            public void onClick(View view)
            {
                Intent intent = new Intent(getApplicationContext(),Main2Activity.class);
                intent.putExtra("String",AddFriend);
                startActivity(intent);
            }
        });

        //------------------back button-----------------
        Button mBack_btn = (Button) findViewById(R.id.back_btn); // sign up button
        mBack_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                startActivity(intent);
                overridePendingTransition(R.anim.fadein, R.anim.fadeout);
                finish();
            }
        });
    }
    @Override
    protected void onStart() {
        super.onStart();

        // setData;
        //dbData = getDbData ()
        // titleTextView.setText(dbData.title)
        // contentTextView.setText(dbData.content)
    }
}
