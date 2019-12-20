/*

    내정보

 */

package com.example.test;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class Main4Activity extends AppCompatActivity {

    TextView usrName= (TextView) findViewById(R.id.usr_name);
    TextView usrAge= (TextView) findViewById(R.id.usr_age);
    TextView usrADDR= (TextView) findViewById(R.id.usr_addr);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main4);

        Button Button1 = (Button) findViewById(R.id.community); // sign in button
        Button Button2 = (Button) findViewById(R.id.FriendList);
        Button Button3 = (Button) findViewById(R.id.alarm);

        Button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                startActivity(intent);overridePendingTransition(0, 0);
                finish();
            }
        });
        Button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getApplicationContext(), Main2Activity.class);
                startActivity(intent);overridePendingTransition(0, 0);
                finish();
            }
        });
        Button3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getApplicationContext(), Main3Activity.class);
                startActivity(intent);overridePendingTransition(0, 0);
                finish();
            }
        });
    }
}
