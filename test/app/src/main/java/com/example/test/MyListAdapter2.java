package com.example.test;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;

public class MyListAdapter2 extends BaseAdapter {
    Context context;
    ArrayList<list_item2> list_itemArrayList;

    public MyListAdapter2(Context context, ArrayList<list_item2> list_itemArrayList) {
        this.context = context;
        this.list_itemArrayList = list_itemArrayList;
    }
    @Override
    public int getCount() {
        /*int getCount()는 이 리스트뷰가 몇개의 아이템을 가지고있는지를 알려주는 함수입니다.*/
        return this.list_itemArrayList.size();
    }

    @Override
    public Object getItem(int position) {
        /* 현재 어떤 아이템인지를 알려주는 부분으로 우리는 arraylist에 저장되있는 객체중 position에 해당하는것을 가져올것*/
        return this.list_itemArrayList.get(position);
    }

    @Override
    public long getItemId(int position) {
        /*현재 어떤 포지션인지를 알려주는 부분*/
        return position;
    }

    TextView nickname_textView;
    ImageView profile_imageView;
    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        /*리스트뷰에서 아이템과 xml을 연결하여 화면에 표시해주는 가장 중요한 부분*/
        /*getView부분에서 반복문이 실행된다고 이해하시면 편하며 순차적으로 한칸씩 화면을 구성해주는 부분*/
        if(convertView==null){
            convertView = LayoutInflater.from(context).inflate(R.layout.item2,null);
            nickname_textView = (TextView)convertView.findViewById(R.id.name);
           // profile_imageView = (ImageView)convertView.findViewById(R.id.profile_imageView);
        }
        nickname_textView.setText(list_itemArrayList.get(position).getNickname());
        //date_textView.setText(list_itemArrayList.get(position).getWrite_date().toString());
        //profile_imageView.setImageResource(list_itemArrayList.get(position).getProfile_image());

        return convertView;
    }
}
