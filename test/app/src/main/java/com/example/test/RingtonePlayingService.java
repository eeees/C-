package com.example.test;

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.media.MediaPlayer;
import android.os.Build;
import android.os.IBinder;
import android.support.annotation.Nullable;
import android.support.v4.app.NotificationCompat;
import android.util.Log;


public class RingtonePlayingService extends Service {
    //이렇게 하면 안 좋대..
    public static MediaPlayer mediaPlayer;
    public static int startId;
    public static boolean isRunning = false;

    @Nullable
    @Override
    public IBinder onBind(Intent intent){
        return null;
    }

    @Override
    public void onCreate(){
        super.onCreate();
        if (Build.VERSION.SDK_INT >= 26){
            String CHANNEL_ID = "defualt";
            NotificationChannel channel = new NotificationChannel(CHANNEL_ID,
                    "Channel human readable title", NotificationManager.IMPORTANCE_DEFAULT);
            ((NotificationManager)getSystemService(Context.NOTIFICATION_SERVICE)).createNotificationChannel(channel);
            Notification notification = new NotificationCompat.Builder(this, CHANNEL_ID)
                    .setContentTitle("알람 시작")
                    .setContentText("알람음이 재생됩니다.")
                    .setSmallIcon(R.mipmap.ic_launcher)
                    .build();
            startForeground(1, notification);
        }
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId){
        String getState = intent.getExtras().getString("state");
        assert getState != null;
        switch (getState){
            case "alarm on":
                startId = 1;
                break;
            case "alarm off":
                startId = 0;
                break;
            default:
                startId = 0;
                break;
        }

        if(!this.isRunning && startId == 1){
            //새 액티비티
            Intent intent1 = new Intent(getApplicationContext(), AlarmScreen.class);
            intent1.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
            //Log.d("에러코드","여기까지왔넹");
            startActivity(intent1);
            //Log.d("에러코드2","여기까지왔넹");
            mediaPlayer = MediaPlayer.create(this, R.raw.good_morning);
            mediaPlayer.start();
            //Log.d("에러코드999","여기까지왔넹");
            this.isRunning = true;
            this.startId = 0;


        }
        else if(this.isRunning && startId == 0){
            mediaPlayer.stop();
            mediaPlayer.reset();
            mediaPlayer.release();
            this.isRunning = false;
            this.startId = 0;
        }
        else if(!this.isRunning && startId == 0){
            this.isRunning = false;
            this.startId = 0;
        }
        else if(this.isRunning && startId == 1){
            this.isRunning = true;
            this.startId = 1;
        }
        else {
        }
        return START_NOT_STICKY;
    }

    @Override
    public void onDestroy() {
        //Log.d("에러코드4","여기까지왔넹");
        super.onDestroy();
        Log.d("onDestroy() 실행", "서비스 파괴");
    }
}
