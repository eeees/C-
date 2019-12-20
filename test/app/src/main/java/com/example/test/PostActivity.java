package com.example.test;

import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.example.test.Database.Daos;
import com.example.test.Database.Users;
import com.example.test.Database.UsersDatabase;

import java.util.ArrayList;
import java.util.concurrent.ExecutionException;


public class PostActivity extends AppCompatActivity {

    private String DataTitle;
    private ArrayList<String> ArrData=new ArrayList<>();

    //static Integer cnt;
    private final String TAG = "PostActivity";
    ArrayList mListItem = new ArrayList();
    Button mAddButton;
    EditText mInputText;
    EditText mInputTitle;
    String SendTitle;
    String SendText;
    int cnt=0;
    //TextView mOutputText;
    // mListItem.clear();
    @Override
    protected void onCreate(Bundle savedInstanceState){

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_post);
        mAddButton=(Button)findViewById(R.id.plus);
        mInputText=(EditText)findViewById(R.id.text);
        mInputTitle=(EditText)findViewById(R.id.title);

        final UsersDatabase db = UsersDatabase.getAppDatabase(this);

        //ArrData.add(mInputTitle.getText().toString());
        //ArrData.add(mInputText.getText().toString());

        mAddButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                cnt=cnt+1;
                Intent intent=new Intent(getApplicationContext(),MainActivity.class);
                //Intent intent_go=new Intent(getApplicationContext(),MainActivity.class);
                intent.putExtra("titleString",mInputTitle.getText().toString());
                //intent_go.putExtra("cntValue",cnt);
                // Log.d(TAG,"글저장\n"+"총 : "+cnt.toString());

                //   startActivity(intent_go);
                startActivity(intent);



                // mOutputText.setText(mInputText.getText());
                //   mAdapter.notifyDataSetChanged();
                finish();
            }
        });

        Button mCancel_btn = (Button) findViewById(R.id.cancel_btn); // sign up button


        // event handler

        mCancel_btn.setOnClickListener(new View.OnClickListener() {
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

    public static class InsertAsyncTask extends AsyncTask<Users, Void, Void> {
        private Daos mDao;

        public  InsertAsyncTask(Daos dao){
            this.mDao = dao;
        }

        @Override //백그라운드작업(메인스레드 X)
        protected Void doInBackground(Users... users) {
            //추가만하고 따로 SELECT문을 안해도 라이브데이터로 인해
            //getAll()이 반응해서 데이터를 갱신해서 보여줄 것이다,  메인액티비티에 옵저버에 쓴 코드가 실행된다. (라이브데이터는 스스로 백그라운드로 처리해준다.)
            mDao.insertUser(users);
            return null;
        }
    }
}
