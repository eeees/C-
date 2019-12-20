package com.example.test;

import android.support.v7.widget.RecyclerView;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;


public class RecyclerViewHolder2 extends RecyclerView.ViewHolder {

    public TextView mName;
    public ImageView mColor;

    public RecyclerViewHolder2(View itemView){
        super(itemView);


        mName=(TextView)itemView.findViewById(R.id.name);
        mColor=(ImageView)itemView.findViewById(R.id.colorDng); //view로한...
    }
}
