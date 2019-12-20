package com.example.test;

import android.app.Activity;
import android.arch.lifecycle.Observer;
import android.arch.lifecycle.ViewModelProviders;
import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.annotation.StringRes;
import android.support.v7.app.AppCompatActivity;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.KeyEvent;
import android.view.View;
import android.view.inputmethod.EditorInfo;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

import com.example.test.Database.Daos;
import com.example.test.Database.Users;
import com.example.test.Database.UsersDatabase;
import com.example.test.R;
import com.example.test.ui.login.LoginViewModel;
import com.example.test.ui.login.LoginViewModelFactory;

import android.view.View.OnClickListener;

import java.util.concurrent.ExecutionException;

public class LoginActivity extends AppCompatActivity {

    private EditText mEmailView;
    private EditText mPasswordView;
    public Daos mdao;
    static String bInputId;
    static String bInputPw;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        //signup signup = new signup();

        final UsersDatabase db = UsersDatabase.getAppDatabase(this);

        // Set up the login form.

        mEmailView = (EditText) findViewById(R.id.email);
        mPasswordView = (EditText) findViewById(R.id.password);

        // event handler

        mEmailView.setOnEditorActionListener(new TextView.OnEditorActionListener()
        {
            @Override
            public boolean onEditorAction(TextView textView, int id, KeyEvent keyEvent) {
                if(id == EditorInfo.IME_ACTION_DONE || id == EditorInfo.IME_NULL){
                    return true;
                }
                return false;
            }

        });
        mPasswordView.setOnEditorActionListener(new TextView.OnEditorActionListener() {
            @Override
            public boolean onEditorAction(TextView textView, int id, KeyEvent keyEvent) {
                if (id == EditorInfo.IME_ACTION_DONE || id == EditorInfo.IME_NULL) {
                    //attemptLogin();

                    return true;
                }
                return false;
            }
        });

        // Button

        Button mEmailSignInButton = (Button) findViewById(R.id.email_sign_in_button); // sign in button
        Button mEmailSignUpButton = (Button) findViewById(R.id.email_sign_up_button); // sign up button



        // event handler


        mEmailSignInButton.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View view) {

                bInputId = mEmailView.getText().toString();
                bInputPw = mPasswordView.getText().toString();

                String findPw = null;
                try {
                    findPw = new FindAsyncTask(db.mDao()).execute().get();
                } catch (ExecutionException e) {
                    e.printStackTrace();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }


                if(bInputPw == null && bInputId == null) {
                    Toast.makeText(getApplicationContext(), "뭐라도 입력해봐!", Toast.LENGTH_LONG).show();
                }
                if(bInputPw.equals(findPw)) {
                    Intent intent = new Intent(getApplicationContext(), MainActivity.class);
                    startActivity(intent);
                    finish();
                }

                else {
                    Toast.makeText(getApplicationContext(), "wrong!", Toast.LENGTH_LONG).show();
                }

            }
        });

        mEmailSignUpButton.setOnClickListener(new OnClickListener(){
            @Override
            public void onClick(View view) {
                Intent intent = new Intent(getApplicationContext(), signup.class);
                startActivity(intent);
                finish();
            }
        });

    }

    public static class FindAsyncTask extends AsyncTask<Users, Void, String> {
        private Daos mDao;
        private String password;
        private String inputId = bInputId;

        public  FindAsyncTask(Daos dao){
            this.mDao = dao;
        }

        @Override //백그라운드작업(메인스레드 X)
        protected String doInBackground(Users... users) {
            //추가만하고 따로 SELECT문을 안해도 라이브데이터로 인해
            //getAll()이 반응해서 데이터를 갱신해서 보여줄 것이다,  메인액티비티에 옵저버에 쓴 코드가 실행된다. (라이브데이터는 스스로 백그라운드로 처리해준다.)
            password = mDao.loadPwById(inputId);
            return password;
        }
    }
}
