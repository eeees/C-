/*

    알람설정

 */

package com.example.test;

import android.app.AlarmManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Build;
import android.os.PowerManager;
import android.support.annotation.RequiresApi;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TimePicker;
import android.widget.Toast;

import java.util.Calendar;

public class Main3Activity extends AppCompatActivity {
    AlarmManager alarmManager;
    TimePicker timePicker;
    Context context;
    PendingIntent pendingIntent;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main3);
        //알람------------------------------------------
        /*초기설정*/
        this.context = this;
        alarmManager = (AlarmManager)getSystemService(ALARM_SERVICE);
        timePicker = findViewById(R.id.time_picker);
        final Calendar calendar = Calendar.getInstance();
        final Intent intent = new Intent(this.context, Alarm_Receiver.class);
        intent.putExtra("state", "alarm off"); //42~43. 초기화 함
        sendBroadcast(intent);

       PowerManager pm = (PowerManager) getApplicationContext().getSystemService(POWER_SERVICE);
        boolean isWhiteListing = false;
        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.M) {
            isWhiteListing = pm.isIgnoringBatteryOptimizations(getApplicationContext().getPackageName());
        }
        if (!isWhiteListing) {
            Intent intent2 = new Intent();
            intent2.setAction(android.provider.Settings.ACTION_REQUEST_IGNORE_BATTERY_OPTIMIZATIONS);
            intent2.setData(Uri.parse("package:" + getApplicationContext().getPackageName()));
           startActivity(intent2);
        }
        /*시작 버튼*/
        Button alarm_on = findViewById(R.id.set_btn);
        alarm_on.setOnClickListener(new View.OnClickListener(){
            @RequiresApi(api = Build.VERSION_CODES.M)
            @Override
            public void onClick(View v){
                calendar.set(Calendar.HOUR_OF_DAY, timePicker.getHour());
                calendar.set(Calendar.MINUTE, timePicker.getMinute());
                int hour = timePicker.getHour();
                int minute = timePicker.getMinute();
                Toast.makeText(Main3Activity.this, "알람이 설정되었습니다.", Toast.LENGTH_SHORT).show();
                intent.putExtra("state", "alarm on");
                pendingIntent = PendingIntent.getBroadcast(Main3Activity.this, 0, intent, PendingIntent.FLAG_UPDATE_CURRENT);
                alarmManager.set(AlarmManager.RTC_WAKEUP, calendar.getTimeInMillis(), pendingIntent);
            }
        });


        /*정지버튼*/
        Button alarm_off = findViewById(R.id.release_btn);
        alarm_off.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v){
                Toast.makeText(Main3Activity.this, "알람이 해제되었습니다.", Toast.LENGTH_SHORT).show();
                alarmManager.cancel(pendingIntent);
                intent.putExtra("state", "alarm off");
                sendBroadcast(intent);
            }
        });
        //버튼------------------------------------------
        Button Button1 = (Button) findViewById(R.id.community); // sign in button
        Button Button2 = (Button) findViewById(R.id.FriendList);
        Button Button4 = (Button) findViewById(R.id.information);

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
        Button4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getApplicationContext(), Main4Activity.class);
                startActivity(intent);overridePendingTransition(0, 0);
                finish();
            }
        });
        //------------------------------------------------
    }
}
