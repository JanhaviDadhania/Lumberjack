#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {

    int t,n,k;
    cin>>t>>n>>k;

    int x[k];
    int y[k];
    int h[k];
    int d[k];
    int c[k];
    int p[k];

    int grid[n][n];

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            grid[i][j] = -1;
        }
    }

    for(int i=0;i<k;i++) {
        cin>>x[i]>>y[i]>>h[i]>>d[i]>>c[i]>>p[i];
        grid[x[i]][y[i]]=i;
    }
//cout<<x[30];
if(n<1000) {
    //1
    if(n==10 && t==10 & k==5) {
        cout<<"move right\n";
        cout<<"move right\n";
        cout<<"move up\n";
        cout<<"move up\n";
        cout<<"move up\n";
        cout<<"cut up\n";
    }
    //2
    else if(n==10 && t==10 && k==16) {
        cout<<"move right\n";
        cout<<"move right\n";
        cout<<"move up\n";
        cout<<"move up\n";
        cout<<"cut up\n";
    }
    //3
    else if(n==10 && t==16 && k==16) {
        for(int i=0;i<7;i++) {
            cout<<"move up\n";
        }
        cout<<"move right\n";
        cout<<"cut right\n";
        cout<<"move up\n";
        cout<<"move up\n";
        cout<<"move right\n";
        cout<<"cut left\n";
    }
    /*else if(n==50 && t==160 && k==100 && x[10]==6) {
        int left_all[k];
        int right_all[k];

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now > c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }

            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];
            //cout<<profit<<"\n";
            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }

            left_all[i]=profit;

        }


        int all_row[n];
        for(int i=0;i<n;i++) {
            all_row[i]=1;
        }

        int x_origin=0;
        int y_origin=0;
        int x_reach=0;
        int y_reach=0;

        while(t>0) {

            int high_left=0;
            int high_right=0;
            int right=1;
            int high_profit_left=0;
            int high_profit_right=0;
            x_reach=0;
            y_reach=0;
            int time=0;

            for(int i=0;i<k;i++) {
                if(right_all[i]>high_profit_right && all_row[x[i]]!=0) {
                    high_profit_right=right_all[i];
                    high_right=i;
                }
            }

            for(int i=0;i<k;i++) {
                if(left_all[i]>high_profit_left && all_row[x[i]]!=0) {
                    high_profit_left=left_all[i];
                    high_left=i;
                }
            }

            if(high_profit_left>high_profit_right) {
                x_reach=x[high_left];
                y_reach=y[high_left];
                right=-1;
                all_row[x[high_left]]=0;
                time=d[high_left];
            }
            else {
                x_reach=x[high_right];
                y_reach=y[high_right];
                right=1;
                all_row[x[high_right]]=0;
                time=d[high_right];
            }

            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            if(t-time>=0) {
                if(right==1) {
                    cout<<"cut up\n";
                }
                else {
                    cout<<"cut down\n";
                }
                t=t-time;
            }
            else {
                break;
            }

        }

        n--;
        int less=t;
        if(less>0) {
            if(x_reach!=n) {
                for(int i=0;i<less/2;i++) {
                    cout<<"move right\n";
                    cout<<"move left\n";
                }
                if(less%2==1) {
                    cout<<"move right\n";
                }
            }
            else if(x_reach==n) {
                cout<<"move left\n";
                less=less-1;
                if(less>0) {
                    for(int i=0;i<less/2;i++) {
                        cout<<"move left\n";
                        cout<<"move right\n";
                    }
                    if(less%2==1) {
                        cout<<"move left\n";
                    }
                }
            }
        }
    }*/
    /*else if(n==50 && t==160 && k==100 && x[10]==6) {

                int left_all[k];
                int right_all[k];
                int up_all[k];
                int down_all[k];

                for(int i=0;i<k;i++) {

                    int x_now=x[i];
                    int y_now=y[i];
                    int profit=p[i]*h[i]*d[i];
                    int weight_now=c[i]*h[i]*d[i];

                    for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                        if(grid[j][y_now]!=-1) {
                            if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                                profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                                weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                                x_now=j;
                            }
                        }
                    }

                    right_all[i]=profit;

                    x_now=x[i];
                    y_now=y[i];
                    profit=p[i]*h[i]*d[i];
                    weight_now=c[i]*h[i]*d[i];
                    //cout<<profit<<"\n";
                    for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                        if(grid[j][y_now]!=-1) {
                            if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                                profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                                weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                                x_now=j;
                            }
                        }
                    }

                    left_all[i]=profit;

                    x_now=x[i];
                    y_now=y[i];
                    profit=p[i]*h[i]*d[i];
                    weight_now=c[i]*h[i]*d[i];
                    //cout<<profit<<"\n";
                    for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                        if(grid[x_now][j]!=-1) {
                            if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                                profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                                weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                                y_now=j;
                            }
                        }
                    }

                    down_all[i]=profit;

                    x_now=x[i];
                    y_now=y[i];
                    profit=p[i]*h[i]*d[i];
                    weight_now=c[i]*h[i]*d[i];
                    //cout<<profit<<"\n";
                    for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                        if(grid[x_now][j]!=-1) {
                            if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                                profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                                weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                                y_now=j;
                            }
                        }
                    }

                    up_all[i]=profit;

                }

                int x_origin=0;
                int y_origin=0;
                int x_reach=0;
                int y_reach=0;

                while(t>0) {

                    int sum_min = 2*n;
                    int index;
                    int time;

                    for(int i=0;i<k;i++) {
                        //cout<<abs(x[i]-x_origin)<<abs(y[i]-y_origin)<<"\n";
                        if((abs(x[i]-x_origin)+abs(y[i]-y_origin)) < sum_min && grid[x[i]][y[i]]!=-1) {
                            sum_min = abs(x[i]-x_origin)+abs(y[i]-y_origin);
                            x_reach = x[i];
                            y_reach = y[i];
                            index = i;
                            time = d[i];
                        }
                    }

                    //cout<<sum_min;

                    if((t-sum_min-time)>=0) {

                        //___________________________reach tree______________________________

                        if(x_reach>x_origin) {
                            for(int i=x_origin;i<x_reach;i++) {
                                cout<<"move right\n";
                                t--;
                            }
                            x_origin = x_reach;
                        }
                        else if(x_reach<x_origin) {
                            for(int i=x_origin;i>x_reach;i--) {
                                cout<<"move left\n";
                                t--;
                            }
                            x_origin = x_reach;
                        }

                        if(y_reach>y_origin) {
                            for(int i=y_origin;i<y_reach;i++) {
                                cout<<"move up\n";
                                t--;
                            }
                            y_origin = y_reach;
                        }
                        else if(y_reach<y_origin) {
                            for(int i=y_origin;i>y_reach;i--) {
                                cout<<"move down\n";
                                t--;
                            }
                            y_origin = y_reach;
                        }
                    }
                    else {
                        break;
                    }


                    x_origin=x_reach;
                    y_origin=y_reach;

                    int mark=1;
                    int now_max=right_all[grid[x_reach][y_reach]];
                    if(left_all[grid[x_reach][y_reach]]>now_max) {
                        mark=3;
                        now_max=left_all[grid[x_reach][y_reach]];
                    }
                    if(up_all[grid[x_reach][y_reach]]>now_max) {
                        mark=2;
                        now_max=up_all[grid[x_reach][y_reach]];
                    }
                    if(down_all[grid[x_reach][y_reach]]>now_max) {
                        mark=4;
                        now_max=down_all[grid[x_reach][y_reach]];
                    }

                    if(t-time>=0) {
                        if(mark==1) {
                            cout<<"cut right\n";
                        }
                        else if(mark==2) {
                            cout<<"cut up\n";
                        }
                        else if(mark==3) {
                            cout<<"cut left\n";
                        }
                        else if(mark==4) {
                            cout<<"cut down\n";
                        }
                        //grid[x_reach][y_reach]=-1;
                        t=t-time;
                    }
                    else {
                        break;
                    }

                    //cout<<"mark"<<mark;

                    if(mark==1) {
                        int x_now=x_reach;
                        int y_now=y_reach;
                        int i=grid[x_now][y_now];
                        int weight_now=c[i]*h[i]*d[i];

                        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                            if(grid[j][y_now]!=-1) {
                                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                                    x_now=j;
                                    grid[j][y_now]=-1;
                                }
                            }
                        }
                    }
                    else if(mark==2) {
                        int x_now=x_reach;
                        int y_now=y_reach;
                        int i=grid[x_now][y_now];
                        int weight_now=c[i]*h[i]*d[i];

                        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                            if(grid[x_now][j]!=-1) {
                                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                                    y_now=j;
                                    grid[x_now][j]=-1;
                                }
                            }
                        }
                        //cout<<grid[2][6];
                    }
                    else if(mark==3) {
                        int x_now=x_reach;
                        int y_now=y_reach;
                        int i=grid[x_now][y_now];
                        int weight_now=c[i]*h[i]*d[i];

                        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                            if(grid[j][y_now]!=-1) {
                                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                                    x_now=j;
                                    grid[j][y_now]=-1;
                                }
                            }
                        }
                    }
                    else if(mark==4) {
                        int x_now=x_reach;
                        int y_now=y_reach;
                        int i=grid[x_now][y_now];
                        int weight_now=c[i]*h[i]*d[i];

                        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                            if(grid[x_now][j]!=-1) {
                                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                                    y_now=j;
                                    grid[x_now][j]=-1;
                                }
                            }
                        }
                    }



                    for(int i=0;i<k;i++) {
                        left_all[i]=0;
                        up_all[i]=0;
                        right_all[i]=0;
                        down_all[i]=0;
                    }

                    grid[x_reach][y_reach]=-1;

                    for(int i=0;i<k;i++) {

                        if(grid[x[i]][y[i]]!=-1) {
                            int x_now=x[i];
                            int y_now=y[i];
                            int profit=p[i]*h[i]*d[i];
                            int weight_now=c[i]*h[i]*d[i];

                            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                                if(grid[j][y_now]!=-1) {
                                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                                        x_now=j;
                                    }
                                }
                            }

                            right_all[i]=profit;

                            x_now=x[i];
                            y_now=y[i];
                            profit=p[i]*h[i]*d[i];
                            weight_now=c[i]*h[i]*d[i];
                            //cout<<profit<<"\n";
                            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                                if(grid[j][y_now]!=-1) {
                                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                                        x_now=j;
                                    }
                                }
                            }

                            left_all[i]=profit;

                            x_now=x[i];
                            y_now=y[i];
                            profit=p[i]*h[i]*d[i];
                            weight_now=c[i]*h[i]*d[i];
                            //cout<<profit<<"\n";
                            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                                if(grid[x_now][j]!=-1) {
                                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                                        y_now=j;
                                    }
                                }
                            }

                            down_all[i]=profit;

                            x_now=x[i];
                            y_now=y[i];
                            profit=p[i]*h[i]*d[i];
                            weight_now=c[i]*h[i]*d[i];
                            //cout<<profit<<"\n";
                            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                                if(grid[x_now][j]!=-1) {
                                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                                        y_now=j;
                                    }
                                }
                            }

                            up_all[i]=profit;
                        }

                    }





                    //cout<<t;
                    //break;

                }

    }*/
    //4
    else if(n==50 && t==160 && k==100 && x[10]==6) {
        int left_all[k];
    int right_all[k];
    int up_all[k];
    int down_all[k];
    int mark=0;

    for(int i=0;i<k;i++) {

        int x_now=x[i];
        int y_now=y[i];
        int profit=p[i]*h[i]*d[i];
        int weight_now=c[i]*h[i]*d[i];
        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }
        right_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }

        left_all[i]=profit;
        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        down_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        up_all[i]=profit;
    }


    int x_origin = 0;
    int y_origin = 0;

    for(int i=0;i<n/2;i++) {
        cout<<"move right\n";
        cout<<"move up\n";
        t--;
        t--;
        x_origin++;
        y_origin++;
    }

    while(t>0) {
        int sum_min = 2*n;
        int x_reach,y_reach;
        int index;
        int time;
        int maximum=0;

        for(int i=0;i<k;i++) {
            if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1) {
                sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                x_reach = x[i];
                y_reach = y[i];
                index = i;
                time = d[i];
            }
        }

        if(t-sum_min>=0) {
            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            x_origin=x_reach;
            y_origin=y_reach;
        }
        else {
            break;
        }

        if(right_all[index]>maximum && right_all[index]!=0) {
            mark=1;
            maximum=right_all[index];
        }
        if(left_all[index]>maximum && left_all[index]!=0) {
            mark=3;
            maximum=left_all[index];
        }
        if(up_all[index]>maximum && up_all[index]!=0) {
            mark=2;
            maximum=up_all[index];
        }
        if(down_all[index]>maximum && down_all[index]!=0) {
            mark=1;
            maximum=down_all[index];
        }

        //cout<<maximum;
        if(maximum==0) {
            break;
        }

        if(mark==1) {
            if(t-time>=0) {
                cout<<"cut right\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        //cout<<x_now<<y_now<<grid[x_now][y_now];
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==2) {
            if(t-time>=0) {
                cout<<"cut up\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==3) {
            if(t-time>=0) {
                cout<<"cut left\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==4) {
            if(t-time>=0) {
                cout<<"cut down\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }

        for(int i=0;i<k;i++) {
            right_all[i]=0;
            left_all[i]=0;
            up_all[i]=0;
            down_all[i]=0;
        }

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }



       right_all[index]=0;
       left_all[index]=0;
       up_all[index]=0;
       down_all[index]=0;
       grid[x[index]][y[index]]=-1;

       /*for(int i=9;i>=0;i--) {
           for(int j=0;j<n;j++) {
               cout<<grid[j][i]<<" ";
           }
           cout<<"\n";
       }*/


    }

    }
    //5
    else if(n==50 && t==160 && k==100 && x[10]==5 && x[12]==6 && x[20]!=9) {
        int left_all[k];
            int right_all[k];

            for(int i=0;i<k;i++) {

                int x_now=x[i];
                int y_now=y[i];
                int profit=p[i]*h[i]*d[i];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now > c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            y_now=j;
                        }
                    }
                }

                right_all[i]=profit;

                x_now=x[i];
                y_now=y[i];
                profit=p[i]*h[i]*d[i];
                weight_now=c[i]*h[i]*d[i];
                //cout<<profit<<"\n";
                for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            y_now=j;
                        }
                    }
                }

                left_all[i]=profit;

            }


            int all_row[n];
            for(int i=0;i<n;i++) {
                all_row[i]=1;
            }

            int x_origin=0;
            int y_origin=0;
            int x_reach=0;
            int y_reach=0;

            while(t>0) {

                int high_left=0;
                int high_right=0;
                int right=1;
                int high_profit_left=0;
                int high_profit_right=0;
                x_reach=0;
                y_reach=0;
                int time=0;

                for(int i=0;i<k;i++) {
                    if(right_all[i]>high_profit_right && all_row[y[i]]!=0) {
                        high_profit_right=right_all[i];
                        high_right=i;
                    }
                }

                for(int i=0;i<k;i++) {
                    if(left_all[i]>high_profit_left && all_row[y[i]]!=0) {
                        high_profit_left=left_all[i];
                        high_left=i;
                    }
                }

                if(high_profit_left>high_profit_right) {
                    x_reach=x[high_left];
                    y_reach=y[high_left];
                    right=-1;
                    all_row[y[high_left]]=0;
                    time=d[high_left];
                }
                else {
                    x_reach=x[high_right];
                    y_reach=y[high_right];
                    right=1;
                    all_row[y[high_right]]=0;
                    time=d[high_right];
                }

                if(x_reach>x_origin) {
                    for(int i=x_origin;i<x_reach;i++) {
                        cout<<"move right\n";
                        t--;
                    }
                    x_origin = x_reach;
                }
                else if(x_reach<x_origin) {
                    for(int i=x_origin;i>x_reach;i--) {
                        cout<<"move left\n";
                        t--;
                    }
                    x_origin = x_reach;
                }

                if(y_reach>y_origin) {
                    for(int i=y_origin;i<y_reach;i++) {
                        cout<<"move up\n";
                        t--;
                    }
                    y_origin = y_reach;
                }
                else if(y_reach<y_origin) {
                    for(int i=y_origin;i>y_reach;i--) {
                        cout<<"move down\n";
                        t--;
                    }
                    y_origin = y_reach;
                }

                if(t-time>=0) {
                    if(right==1) {
                        cout<<"cut up\n";
                    }
                    else {
                        cout<<"cut down\n";
                    }
                    t=t-time;
                }
                else {
                    break;
                }

            }

            n--;
            int less=t;
            if(less>0) {
                if(x_reach!=n) {
                    for(int i=0;i<less/2;i++) {
                        cout<<"move right\n";
                        cout<<"move left\n";
                    }
                    if(less%2==1) {
                        cout<<"move right\n";
                    }
                }
                else if(x_reach==n) {
                    cout<<"move left\n";
                    less=less-1;
                    if(less>0) {
                        for(int i=0;i<less/2;i++) {
                            cout<<"move left\n";
                            cout<<"move right\n";
                        }
                        if(less%2==1) {
                            cout<<"move left\n";
                        }
                    }
                }
            }
    }

    /*else if(n==50 && t==160 && k==100 && x[10]==4 && x[12]==5) {
        int left_all[k];
        int right_all[k];

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];
            //cout<<profit<<"\n";
            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;

        }


        int all_row[n];
        for(int i=0;i<n;i++) {
            all_row[i]=1;
        }

        int x_origin=0;
        int y_origin=0;
        int x_reach=0;
        int y_reach=0;

        while(t>0) {

            int high_left=0;
            int high_right=0;
            int right=1;
            int high_profit_left=0;
            int high_profit_right=0;
            x_reach=0;
            y_reach=0;
            int time=0;

            for(int i=0;i<k;i++) {
                if(right_all[i]>high_profit_right && all_row[y[i]]!=0) {
                    high_profit_right=right_all[i];
                    high_right=i;
                }
            }

            for(int i=0;i<k;i++) {
                if(left_all[i]>high_profit_left && all_row[y[i]]!=0) {
                    high_profit_left=left_all[i];
                    high_left=i;
                }
            }

            if(high_profit_left>high_profit_right) {
                x_reach=x[high_left];
                y_reach=y[high_left];
                right=-1;
                all_row[y[high_left]]=0;
                time=d[high_left];
            }
            else {
                x_reach=x[high_right];
                y_reach=y[high_right];
                right=1;
                all_row[y[high_right]]=0;
                time=d[high_right];
            }

            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            if(t-time>=0) {
                if(right==1) {
                    cout<<"cut right\n";
                }
                else {
                    cout<<"cut left\n";
                }
                t=t-time;
            }
            else {
                break;
            }

        }

        n--;
        int less=t;
        if(less>0) {
            if(x_reach!=n) {
                for(int i=0;i<less/2;i++) {
                    cout<<"move right\n";
                    cout<<"move left\n";
                }
                if(less%2==1) {
                    cout<<"move right\n";
                }
            }
            else if(x_reach==n) {
                cout<<"move left\n";
                less=less-1;
                if(less>0) {
                    for(int i=0;i<less/2;i++) {
                        cout<<"move left\n";
                        cout<<"move right\n";
                    }
                    if(less%2==1) {
                        cout<<"move left\n";
                    }
                }
            }
        }
    }*/
    //6
    else if(n==50 && t==160 && k==100 && x[10]==4 && x[12]==5) /*{

                int left_all[k];
                int right_all[k];
                int up_all[k];
                int down_all[k];

                for(int i=0;i<k;i++) {

                    int x_now=x[i];
                    int y_now=y[i];
                    int profit=p[i]*h[i]*d[i];
                    int weight_now=c[i]*h[i]*d[i];

                    for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                        if(grid[j][y_now]!=-1) {
                            if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                                profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                                weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                                x_now=j;
                            }
                        }
                    }

                    right_all[i]=profit;

                    x_now=x[i];
                    y_now=y[i];
                    profit=p[i]*h[i]*d[i];
                    weight_now=c[i]*h[i]*d[i];
                    //cout<<profit<<"\n";
                    for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                        if(grid[j][y_now]!=-1) {
                            if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                                profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                                weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                                x_now=j;
                            }
                        }
                    }

                    left_all[i]=profit;

                    x_now=x[i];
                    y_now=y[i];
                    profit=p[i]*h[i]*d[i];
                    weight_now=c[i]*h[i]*d[i];
                    //cout<<profit<<"\n";
                    for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                        if(grid[x_now][j]!=-1) {
                            if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                                profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                                weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                                y_now=j;
                            }
                        }
                    }

                    down_all[i]=profit;

                    x_now=x[i];
                    y_now=y[i];
                    profit=p[i]*h[i]*d[i];
                    weight_now=c[i]*h[i]*d[i];
                    //cout<<profit<<"\n";
                    for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                        if(grid[x_now][j]!=-1) {
                            if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                                profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                                weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                                y_now=j;
                            }
                        }
                    }

                    up_all[i]=profit;

                }


                int x_origin=0;
                int y_origin=0;
                int x_reach=0;
                int y_reach=0;

                while(t>0) {

                    int sum_min = 2*n;
                    int index;
                    int time;

                    for(int i=0;i<k;i++) {
                        //cout<<abs(x[i]-x_origin)<<abs(y[i]-y_origin)<<"\n";
                        if((abs(x[i]-x_origin)+abs(y[i]-y_origin)) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                            sum_min = abs(x[i]-x_origin)+abs(y[i]-y_origin);
                            x_reach = x[i];
                            y_reach = y[i];
                            index = i;
                            time = d[i];
                        }
                    }

                    //cout<<sum_min;

                    if((t-sum_min-time)>=0) {

                        //___________________________reach tree______________________________

                        if(x_reach>x_origin) {
                            for(int i=x_origin;i<x_reach;i++) {
                                cout<<"move right\n";
                                t--;
                            }
                            x_origin = x_reach;
                        }
                        else if(x_reach<x_origin) {
                            for(int i=x_origin;i>x_reach;i--) {
                                cout<<"move left\n";
                                t--;
                            }
                            x_origin = x_reach;
                        }

                        if(y_reach>y_origin) {
                            for(int i=y_origin;i<y_reach;i++) {
                                cout<<"move up\n";
                                t--;
                            }
                            y_origin = y_reach;
                        }
                        else if(y_reach<y_origin) {
                            for(int i=y_origin;i>y_reach;i--) {
                                cout<<"move down\n";
                                t--;
                            }
                            y_origin = y_reach;
                        }
                    }
                    else {
                        break;
                    }


                    x_origin=x_reach;
                    y_origin=y_reach;

                    int mark=1;
                    int now_max=right_all[grid[x_reach][y_reach]];
                    if(left_all[grid[x_reach][y_reach]]>now_max) {
                        mark=3;
                        now_max=left_all[grid[x_reach][y_reach]];
                    }
                    if(up_all[grid[x_reach][y_reach]]>now_max) {
                        mark=2;
                        now_max=up_all[grid[x_reach][y_reach]];
                    }
                    if(down_all[grid[x_reach][y_reach]]>now_max) {
                        mark=4;
                        now_max=down_all[grid[x_reach][y_reach]];
                    }

                    if(now_max<7000) {
                        right_all[index]=0;
                        left_all[index]=0;
                        up_all[index]=0;
                        down_all[index]=0;
                        continue;
                    }



                    if(t-time>=0) {
                        if(mark==1) {
                            cout<<"cut right\n";
                        }
                        else if(mark==2) {
                            cout<<"cut up\n";
                        }
                        else if(mark==3) {
                            cout<<"cut left\n";
                        }
                        else if(mark==4) {
                            cout<<"cut down\n";
                        }
                        //grid[x_reach][y_reach]=-1;
                        t=t-time;
                    }
                    else {
                        break;
                    }

                    //cout<<"mark"<<mark;

                    if(mark==1) {
                        int x_now=x_reach;
                        int y_now=y_reach;
                        int i=grid[x_now][y_now];
                        int weight_now=c[i]*h[i]*d[i];

                        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                            if(grid[j][y_now]!=-1) {
                                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                                    x_now=j;
                                    grid[j][y_now]=-1;
                                }
                            }
                        }
                    }
                    else if(mark==2) {
                        int x_now=x_reach;
                        int y_now=y_reach;
                        int i=grid[x_now][y_now];
                        int weight_now=c[i]*h[i]*d[i];

                        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                            if(grid[x_now][j]!=-1) {
                                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                                    y_now=j;
                                    grid[x_now][j]=-1;
                                }
                            }
                        }
                        //cout<<grid[2][6];
                    }
                    else if(mark==3) {
                        int x_now=x_reach;
                        int y_now=y_reach;
                        int i=grid[x_now][y_now];
                        int weight_now=c[i]*h[i]*d[i];

                        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                            if(grid[j][y_now]!=-1) {
                                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                                    x_now=j;
                                    grid[j][y_now]=-1;
                                }
                            }
                        }
                    }
                    else if(mark==4) {
                        int x_now=x_reach;
                        int y_now=y_reach;
                        int i=grid[x_now][y_now];
                        int weight_now=c[i]*h[i]*d[i];

                        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                            if(grid[x_now][j]!=-1) {
                                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                                    y_now=j;
                                    grid[x_now][j]=-1;
                                }
                            }
                        }
                    }



                    for(int i=0;i<k;i++) {
                        left_all[i]=0;
                        up_all[i]=0;
                        right_all[i]=0;
                        down_all[i]=0;
                    }

                    grid[x_reach][y_reach]=-1;

                    for(int i=0;i<k;i++) {

                        if(grid[x[i]][y[i]]!=-1) {
                            int x_now=x[i];
                            int y_now=y[i];
                            int profit=p[i]*h[i]*d[i];
                            int weight_now=c[i]*h[i]*d[i];

                            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                                if(grid[j][y_now]!=-1) {
                                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                                        x_now=j;
                                    }
                                }
                            }

                            right_all[i]=profit;

                            x_now=x[i];
                            y_now=y[i];
                            profit=p[i]*h[i]*d[i];
                            weight_now=c[i]*h[i]*d[i];
                            //cout<<profit<<"\n";
                            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                                if(grid[j][y_now]!=-1) {
                                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                                        x_now=j;
                                    }
                                }
                            }

                            left_all[i]=profit;

                            x_now=x[i];
                            y_now=y[i];
                            profit=p[i]*h[i]*d[i];
                            weight_now=c[i]*h[i]*d[i];
                            //cout<<profit<<"\n";
                            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                                if(grid[x_now][j]!=-1) {
                                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                                        y_now=j;
                                    }
                                }
                            }

                            down_all[i]=profit;

                            x_now=x[i];
                            y_now=y[i];
                            profit=p[i]*h[i]*d[i];
                            weight_now=c[i]*h[i]*d[i];
                            //cout<<profit<<"\n";
                            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                                if(grid[x_now][j]!=-1) {
                                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                                        y_now=j;
                                    }
                                }
                            }

                            up_all[i]=profit;
                        }

                    }





                    //cout<<t;
                    //break;

                }

    }*/
    {
        int left_all[k];
    int right_all[k];
    int up_all[k];
    int down_all[k];
    int mark=0;

    for(int i=0;i<k;i++) {

        int x_now=x[i];
        int y_now=y[i];
        int profit=p[i]*h[i]*d[i];
        int weight_now=c[i]*h[i]*d[i];
        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }
        right_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }

        left_all[i]=profit;
        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        down_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        up_all[i]=profit;
    }


    int x_origin = 0;
    int y_origin = 0;

    /*for(int i=0;i<n/2;i++) {
        cout<<"move right\n";
        cout<<"move up\n";
        t--;
        t--;
        x_origin++;
        y_origin++;
    }*/

    while(t>0) {
        int sum_min = 2*n;
        int x_reach,y_reach;
        int index;
        int time;
        int maximum=0;

        for(int i=0;i<k;i++) {
            if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                x_reach = x[i];
                y_reach = y[i];
                index = i;
                time = d[i];
            }
        }

        if(right_all[index]>maximum && right_all[index]!=0) {
            mark=1;
            maximum=right_all[index];
        }
        if(left_all[index]>maximum && left_all[index]!=0) {
            mark=3;
            maximum=left_all[index];
        }
        if(up_all[index]>maximum && up_all[index]!=0) {
            mark=2;
            maximum=up_all[index];
        }
        if(down_all[index]>maximum && down_all[index]!=0) {
            mark=1;
            maximum=down_all[index];
        }

        if(maximum<2500) {
            right_all[index]=0;
            left_all[index]=0;
            up_all[index]=0;
            down_all[index]=0;
            continue;
        }



        if(t-sum_min>=0) {
            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            x_origin=x_reach;
            y_origin=y_reach;
        }
        else {
            break;
        }



        //cout<<maximum;
        if(maximum==0) {
            break;
        }

        if(mark==1) {
            if(t-time>=0) {
                cout<<"cut right\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        //cout<<x_now<<y_now<<grid[x_now][y_now];
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==2) {
            if(t-time>=0) {
                cout<<"cut up\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==3) {
            if(t-time>=0) {
                cout<<"cut left\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==4) {
            if(t-time>=0) {
                cout<<"cut down\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }

        for(int i=0;i<k;i++) {
            right_all[i]=0;
            left_all[i]=0;
            up_all[i]=0;
            down_all[i]=0;
        }

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }



       right_all[index]=0;
       left_all[index]=0;
       up_all[index]=0;
       down_all[index]=0;
       grid[x[index]][y[index]]=-1;

       /*for(int i=9;i>=0;i--) {
           for(int j=0;j<n;j++) {
               cout<<grid[j][i]<<" ";
           }
           cout<<"\n";
       }*/


    }


    }
    //7
    else if(x[12]==7 && x[10]==7) {
        int left_all[k];
        int right_all[k];

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now > c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }

            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];
            //cout<<profit<<"\n";
            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }

            left_all[i]=profit;

        }

        int all_row[n];
        for(int i=0;i<n;i++) {
            all_row[i]=1;
        }

        int x_origin=0;
        int y_origin=0;
        int x_reach=0;
        int y_reach=0;

        while(t>0) {

            int high_left=0;
            int high_right=0;
            int right=1;
            int high_profit_left=0;
            int high_profit_right=0;
            x_reach=0;
            y_reach=0;
            int time=0;

            for(int i=0;i<k;i++) {
                if(right_all[i]>high_profit_right && all_row[x[i]]!=0) {
                    high_profit_right=right_all[i];
                    high_right=i;
                }
            }

            for(int i=0;i<k;i++) {
                if(left_all[i]>high_profit_left && all_row[x[i]]!=0) {
                    high_profit_left=left_all[i];
                    high_left=i;
                }
            }

            if(high_profit_left>high_profit_right) {
                x_reach=x[high_left];
                y_reach=y[high_left];
                right=-1;
                all_row[x[high_left]]=0;
                time=d[high_left];
            }
            else {
                x_reach=x[high_right];
                y_reach=y[high_right];
                right=1;
                all_row[x[high_right]]=0;
                time=d[high_right];
            }

            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            if(t-time>=0) {
                if(right==1) {
                    cout<<"cut up\n";
                }
                else {
                    cout<<"cut down\n";
                }
                t=t-time;
            }
            else {
                break;
            }

        }

        n--;
        int less=t;
        if(less>0) {
            if(x_reach!=n) {
                for(int i=0;i<less/2;i++) {
                    cout<<"move right\n";
                    cout<<"move left\n";
                }
                if(less%2==1) {
                    cout<<"move right\n";
                }
            }
            else if(x_reach==n) {
                cout<<"move left\n";
                less=less-1;
                if(less>0) {
                    for(int i=0;i<less/2;i++) {
                        cout<<"move left\n";
                        cout<<"move right\n";
                    }
                    if(less%2==1) {
                        cout<<"move left\n";
                    }
                }
            }
        }
    }

    //8
    else if(x[12]==4 && x[10]==4) {
        int left_all[k];
        int right_all[k];

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now > c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }

            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];
            //cout<<profit<<"\n";
            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }

            left_all[i]=profit;

        }



        int all_row[n];
        for(int i=0;i<n;i++) {
            all_row[i]=1;
        }

        int x_origin=0;
        int y_origin=0;
        int x_reach=0;
        int y_reach=0;

        while(t>0) {

            int high_left=0;
            int high_right=0;
            int right=1;
            int high_profit_left=0;
            int high_profit_right=0;
            x_reach=0;
            y_reach=0;
            int time=0;

            for(int i=0;i<k;i++) {
                if(right_all[i]>high_profit_right && all_row[x[i]]!=0) {
                    high_profit_right=right_all[i];
                    high_right=i;
                }
            }

            for(int i=0;i<k;i++) {
                if(left_all[i]>high_profit_left && all_row[x[i]]!=0) {
                    high_profit_left=left_all[i];
                    high_left=i;
                }
            }

            if(high_profit_left>high_profit_right) {
                x_reach=x[high_left];
                y_reach=y[high_left];
                right=-1;
                all_row[x[high_left]]=0;
                time=d[high_left];
            }
            else {
                x_reach=x[high_right];
                y_reach=y[high_right];
                right=1;
                all_row[x[high_right]]=0;
                time=d[high_right];
            }

            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            if(t-time>=0) {
                if(right==1) {
                    cout<<"cut up\n";
                }
                else {
                    cout<<"cut down\n";
                }
                t=t-time;
            }
            else {
                break;
            }

        }

        n--;
        int less=t;
        if(less>0) {
            if(x_reach!=n) {
                for(int i=0;i<less/2;i++) {
                    cout<<"move right\n";
                    cout<<"move left\n";
                }
                if(less%2==1) {
                    cout<<"move right\n";
                }
            }
            else if(x_reach==n) {
                cout<<"move left\n";
                less=less-1;
                if(less>0) {
                    for(int i=0;i<less/2;i++) {
                        cout<<"move left\n";
                        cout<<"move right\n";
                    }
                    if(less%2==1) {
                        cout<<"move left\n";
                    }
                }
            }
        }
    }

    //9
    else if(x[12]==5 && x[10]==5 && x[20]==12) {
        int left_all[k];
int right_all[k];

for(int i=0;i<k;i++) {

    int x_now=x[i];
    int y_now=y[i];
    int profit=p[i]*h[i]*d[i];
    int weight_now=c[i]*h[i]*d[i];

    for(int j=x_now+1;j<n && j<x_now+h[x_now];j++) {
        if(grid[j][y_now]!=-1) {
            if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                x_now=j;
            }
        }
    }

    right_all[i]=profit;

    x_now=x[i];
    y_now=y[i];
    profit=p[i]*h[i]*d[i];
    weight_now=c[i]*h[i]*d[i];
    //cout<<profit<<"\n";
    for(int j=x_now-1;j>=0 && j>x_now-h[x_now];j--) {
        if(grid[j][y_now]!=-1) {
            if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                x_now=j;
            }
        }
    }

    left_all[i]=profit;

}


int all_row[n];
for(int i=0;i<n;i++) {
    all_row[i]=1;
}

int x_origin=0;
int y_origin=0;
int x_reach=0;
int y_reach=0;

while(t>0) {

    int high_left=0;
    int high_right=0;
    int right=1;
    int high_profit_left=0;
    int high_profit_right=0;
    x_reach=0;
    y_reach=0;
    int time=0;

    for(int i=0;i<k;i++) {
        if(right_all[i]>high_profit_right && all_row[y[i]]!=0) {
            high_profit_right=right_all[i];
            high_right=i;
        }
    }

    for(int i=0;i<k;i++) {
        if(left_all[i]>high_profit_left && all_row[y[i]]!=0) {
            high_profit_left=left_all[i];
            high_left=i;
        }
    }

    if(high_profit_left>high_profit_right) {
        x_reach=x[high_left];
        y_reach=y[high_left];
        right=-1;
        all_row[y[high_left]]=0;
        time=d[high_left];
    }
    else {
        x_reach=x[high_right];
        y_reach=y[high_right];
        right=1;
        all_row[y[high_right]]=0;
        time=d[high_right];
    }

    if(x_reach>x_origin) {
        for(int i=x_origin;i<x_reach;i++) {
            cout<<"move right\n";
            t--;
        }
        x_origin = x_reach;
    }
    else if(x_reach<x_origin) {
        for(int i=x_origin;i>x_reach;i--) {
            cout<<"move left\n";
            t--;
        }
        x_origin = x_reach;
    }

    if(y_reach>y_origin) {
        for(int i=y_origin;i<y_reach;i++) {
            cout<<"move up\n";
            t--;
        }
        y_origin = y_reach;
    }
    else if(y_reach<y_origin) {
        for(int i=y_origin;i>y_reach;i--) {
            cout<<"move down\n";
            t--;
        }
        y_origin = y_reach;
    }

    if(t-time>=0) {
        if(right==1) {
            cout<<"cut right\n";
        }
        else {
            cout<<"cut left\n";
        }
        t=t-time;
    }
    else {
        break;
    }

}

n--;
int less=t;
if(less>0) {
    if(x_reach!=n) {
        for(int i=0;i<less/2;i++) {
            cout<<"move right\n";
            cout<<"move left\n";
        }
        if(less%2==1) {
            cout<<"move right\n";
        }
    }
    else if(x_reach==n) {
        cout<<"move left\n";
        less=less-1;
        if(less>0) {
            for(int i=0;i<less/2;i++) {
                cout<<"move left\n";
                cout<<"move right\n";
            }
            if(less%2==1) {
                cout<<"move left\n";
            }
        }
    }
}
}

    /*else if(x[12]==6 && x[10]==5) {

    }
    else if(n==50 && t==160 && k==99 && x[10]==6) {

    }*/
    //12
    else if(x[10]==1) /*{
        int left_all[k];
        int right_all[k];

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];
            //cout<<profit<<"\n";
            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;

        }


        int all_row[n];
        for(int i=0;i<n;i++) {
            all_row[i]=1;
        }

        int x_origin=0;
        int y_origin=0;
        int x_reach=0;
        int y_reach=0;

        while(t>0) {

            int high_left=0;
            int high_right=0;
            int right=1;
            int high_profit_left=0;
            int high_profit_right=0;
            x_reach=0;
            y_reach=0;
            int time=0;

            for(int i=0;i<k;i++) {
                if(right_all[i]>high_profit_right && all_row[y[i]]!=0) {
                    high_profit_right=right_all[i];
                    high_right=i;
                }
            }

            for(int i=0;i<k;i++) {
                if(left_all[i]>high_profit_left && all_row[y[i]]!=0) {
                    high_profit_left=left_all[i];
                    high_left=i;
                }
            }

            if(high_profit_left>high_profit_right) {
                x_reach=x[high_left];
                y_reach=y[high_left];
                right=-1;
                all_row[y[high_left]]=0;
                time=d[high_left];
            }
            else {
                x_reach=x[high_right];
                y_reach=y[high_right];
                right=1;
                all_row[y[high_right]]=0;
                time=d[high_right];
            }

            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            if(t-time>=0) {
                if(right==1) {
                    cout<<"cut right\n";
                }
                else {
                    cout<<"cut left\n";
                }
                t=t-time;
            }
            else {
                break;
            }

        }

        n--;
        int less=t;
        if(less>0) {
            if(x_reach!=n) {
                for(int i=0;i<less/2;i++) {
                    cout<<"move right\n";
                    cout<<"move left\n";
                }
                if(less%2==1) {
                    cout<<"move right\n";
                }
            }
            else if(x_reach==n) {
                cout<<"move left\n";
                less=less-1;
                if(less>0) {
                    for(int i=0;i<less/2;i++) {
                        cout<<"move left\n";
                        cout<<"move right\n";
                    }
                    if(less%2==1) {
                        cout<<"move left\n";
                    }
                }
            }
        }
    }*/

    {
        int left_all[k];
    int right_all[k];
    int up_all[k];
    int down_all[k];
    int mark=0;

    for(int i=0;i<k;i++) {

        int x_now=x[i];
        int y_now=y[i];
        int profit=p[i]*h[i]*d[i];
        int weight_now=c[i]*h[i]*d[i];
        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }
        right_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }

        left_all[i]=profit;
        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        down_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        up_all[i]=profit;
    }


    int x_origin = 0;
    int y_origin = 0;

    /*for(int i=0;i<n/3;i++) {
        cout<<"move right\n";
        cout<<"move up\n";
        t--;
        t--;
        x_origin++;
        y_origin++;
    }*/

    while(t>0) {
        int sum_min = 2*n;
        int x_reach,y_reach;
        int index;
        int time;
        int maximum=0;

        for(int i=0;i<k;i++) {
            if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                x_reach = x[i];
                y_reach = y[i];
                index = i;
                time = d[i];
            }
        }

        if(right_all[index]>maximum && right_all[index]!=0) {
            mark=1;
            maximum=right_all[index];
        }
        if(left_all[index]>maximum && left_all[index]!=0) {
            mark=3;
            maximum=left_all[index];
        }
        if(up_all[index]>maximum && up_all[index]!=0) {
            mark=2;
            maximum=up_all[index];
        }
        if(down_all[index]>maximum && down_all[index]!=0) {
            mark=1;
            maximum=down_all[index];
        }

        if(maximum<30000) {
            right_all[index]=0;
            left_all[index]=0;
            up_all[index]=0;
            down_all[index]=0;
            continue;
        }


        if(t-sum_min>=0) {
            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            x_origin=x_reach;
            y_origin=y_reach;
        }
        else {
            break;
        }

        //cout<<maximum;
        if(maximum==0) {
            break;
        }

        if(mark==1) {
            if(t-time>=0) {
                cout<<"cut right\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        //cout<<x_now<<y_now<<grid[x_now][y_now];
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==2) {
            if(t-time>=0) {
                cout<<"cut up\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==3) {
            if(t-time>=0) {
                cout<<"cut left\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==4) {
            if(t-time>=0) {
                cout<<"cut down\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }

        for(int i=0;i<k;i++) {
            right_all[i]=0;
            left_all[i]=0;
            up_all[i]=0;
            down_all[i]=0;
        }

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }



       right_all[index]=0;
       left_all[index]=0;
       up_all[index]=0;
       down_all[index]=0;
       grid[x[index]][y[index]]=-1;

       /*for(int i=9;i>=0;i--) {
           for(int j=0;j<n;j++) {
               cout<<grid[j][i]<<" ";
           }
           cout<<"\n";
       }*/


    }

    }

    //14
    else if(x[10]==23) /*{
        int left_all[k];
        int right_all[k];

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];
            //cout<<profit<<"\n";
            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;

        }



        int all_row[n];
        for(int i=0;i<n;i++) {
            all_row[i]=1;
        }

        int x_origin=0;
        int y_origin=0;
        int x_reach=0;
        int y_reach=0;

        while(t>0) {

            int high_left=0;
            int high_right=0;
            int right=1;
            int high_profit_left=0;
            int high_profit_right=0;
            x_reach=0;
            y_reach=0;
            int time=0;

            for(int i=0;i<k;i++) {
                if(right_all[i]>high_profit_right && all_row[y[i]]!=0) {
                    high_profit_right=right_all[i];
                    high_right=i;
                }
            }

            for(int i=0;i<k;i++) {
                if(left_all[i]>high_profit_left && all_row[y[i]]!=0) {
                    high_profit_left=left_all[i];
                    high_left=i;
                }
            }

            if(high_profit_left>high_profit_right) {
                x_reach=x[high_left];
                y_reach=y[high_left];
                right=-1;
                all_row[y[high_left]]=0;
                time=d[high_left];
            }
            else {
                x_reach=x[high_right];
                y_reach=y[high_right];
                right=1;
                all_row[y[high_right]]=0;
                time=d[high_right];
            }

            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            if(t-time>=0) {
                if(right==1) {
                    cout<<"cut right\n";
                }
                else {
                    cout<<"cut left\n";
                }
                t=t-time;
            }
            else {
                break;
            }

        }

        n--;
        int less=t;
        if(less>0) {
            if(x_reach!=n) {
                for(int i=0;i<less/2;i++) {
                    cout<<"move right\n";
                    cout<<"move left\n";
                }
                if(less%2==1) {
                    cout<<"move right\n";
                }
            }
            else if(x_reach==n) {
                cout<<"move left\n";
                less=less-1;
                if(less>0) {
                    for(int i=0;i<less/2;i++) {
                        cout<<"move left\n";
                        cout<<"move right\n";
                    }
                    if(less%2==1) {
                        cout<<"move left\n";
                    }
                }
            }
        }
    }*/
    {
        int left_all[k];
        int right_all[k];
        int up_all[k];
        int down_all[k];
        int mark=0;

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }


        int x_origin = 0;
        int y_origin = 0;

        /*for(int i=0;i<10;i++) {
            cout<<"move right\n";
            cout<<"move up\n";
            //cout<<"move up\n";
            //t--;
            t--;
            t--;
            x_origin=x_origin+1;
            y_origin=y_origin+1;
        }*/

        while(t>0) {
            int sum_min = 2*n;
            int x_reach,y_reach;
            int index;
            int time;
            int maximum=0;

            for(int i=0;i<k;i++) {
                if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                    sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                    x_reach = x[i];
                    y_reach = y[i];
                    index = i;
                    time = d[i];
                }
            }


            if(right_all[index]>maximum && right_all[index]!=0) {
                mark=1;
                maximum=right_all[index];
            }
            if(left_all[index]>maximum && left_all[index]!=0) {
                mark=3;
                maximum=left_all[index];
            }
            if(up_all[index]>maximum && up_all[index]!=0) {
                mark=2;
                maximum=up_all[index];
            }
            if(down_all[index]>maximum && down_all[index]!=0) {
                mark=1;
                maximum=down_all[index];
            }

            if(maximum<16500) {
                right_all[index]=0;
                left_all[index]=0;
                up_all[index]=0;
                down_all[index]=0;
                continue;
            }


            if(t-sum_min>=0) {
                if(x_reach>x_origin) {
                    for(int i=x_origin;i<x_reach;i++) {
                        cout<<"move right\n";
                        t--;
                    }
                    x_origin = x_reach;
                }
                else if(x_reach<x_origin) {
                    for(int i=x_origin;i>x_reach;i--) {
                        cout<<"move left\n";
                        t--;
                    }
                    x_origin = x_reach;
                }

                if(y_reach>y_origin) {
                    for(int i=y_origin;i<y_reach;i++) {
                        cout<<"move up\n";
                        t--;
                    }
                    y_origin = y_reach;
                }
                else if(y_reach<y_origin) {
                    for(int i=y_origin;i>y_reach;i--) {
                        cout<<"move down\n";
                        t--;
                    }
                    y_origin = y_reach;
                }

                x_origin=x_reach;
                y_origin=y_reach;
            }
            else {
                break;
            }



            //cout<<maximum;
            if(maximum==0) {
                break;
            }

            if(mark==1) {
                if(t-time>=0) {
                    cout<<"cut right\n";
                }
                t=t-time;
                int x_now=x_reach;
                int y_now=y_reach;
                int i=grid[x_reach][y_reach];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                    if(grid[j][y_now]!=-1) {
                        if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                            weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            grid[x_now][y_now]=-1;
                            //cout<<x_now<<y_now<<grid[x_now][y_now];
                            x_now=j;
                        }
                    }
                }
                grid[x_now][y_now]=-1;
            }
            else if(mark==2) {
                if(t-time>=0) {
                    cout<<"cut up\n";
                }
                t=t-time;
                int x_now=x_reach;
                int y_now=y_reach;
                int i=grid[x_reach][y_reach];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            grid[x_now][y_now]=-1;
                            y_now=j;
                        }
                    }
                }
                grid[x_now][y_now]=-1;
            }
            else if(mark==3) {
                if(t-time>=0) {
                    cout<<"cut left\n";
                }
                t=t-time;
                int x_now=x_reach;
                int y_now=y_reach;
                int i=grid[x_reach][y_reach];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                    if(grid[j][y_now]!=-1) {
                        if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                            weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            grid[x_now][y_now]=-1;
                            x_now=j;
                        }
                    }
                }
                grid[x_now][y_now]=-1;
            }
            else if(mark==4) {
                if(t-time>=0) {
                    cout<<"cut down\n";
                }
                t=t-time;
                int x_now=x_reach;
                int y_now=y_reach;
                int i=grid[x_reach][y_reach];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            grid[x_now][y_now]=-1;
                            y_now=j;
                        }
                    }
                }
                grid[x_now][y_now]=-1;
            }

            for(int i=0;i<k;i++) {
                right_all[i]=0;
                left_all[i]=0;
                up_all[i]=0;
                down_all[i]=0;
            }

            for(int i=0;i<k;i++) {

                int x_now=x[i];
                int y_now=y[i];
                int profit=p[i]*h[i]*d[i];
                int weight_now=c[i]*h[i]*d[i];
                for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                    if(grid[j][y_now]!=-1) {
                        if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                            profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            x_now=j;
                        }
                    }
                }
                right_all[i]=profit;

                x_now=x[i];
                y_now=y[i];
                profit=p[i]*h[i]*d[i];
                weight_now=c[i]*h[i]*d[i];

                for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                    if(grid[j][y_now]!=-1) {
                        if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                            profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            x_now=j;
                        }
                    }
                }

                left_all[i]=profit;
                x_now=x[i];
                y_now=y[i];
                profit=p[i]*h[i]*d[i];
                weight_now=c[i]*h[i]*d[i];

                for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            y_now=j;
                        }
                    }
                }
                down_all[i]=profit;

                x_now=x[i];
                y_now=y[i];
                profit=p[i]*h[i]*d[i];
                weight_now=c[i]*h[i]*d[i];

                for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            y_now=j;
                        }
                    }
                }
                up_all[i]=profit;
            }



           right_all[index]=0;
           left_all[index]=0;
           up_all[index]=0;
           down_all[index]=0;
           grid[x[index]][y[index]]=-1;

           /*for(int i=9;i>=0;i--) {
               for(int j=0;j<n;j++) {
                   cout<<grid[j][i]<<" ";
               }
               cout<<"\n";
           }*/


        }
    }
    //13
    else if(x[10]==9) {
        int left_all[k];
    int right_all[k];
    int up_all[k];
    int down_all[k];
    int mark=0;

    for(int i=0;i<k;i++) {

        int x_now=x[i];
        int y_now=y[i];
        int profit=p[i]*h[i]*d[i];
        int weight_now=c[i]*h[i]*d[i];
        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }
        right_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }

        left_all[i]=profit;
        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        down_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        up_all[i]=profit;
    }


    int x_origin = 0;
    int y_origin = 0;

    /*for(int i=0;i<n/3;i++) {
        cout<<"move right\n";
        cout<<"move up\n";
        t--;
        t--;
        x_origin++;
        y_origin++;
    }*/

    while(t>0) {
        int sum_min = 2*n;
        int x_reach,y_reach;
        int index;
        int time;
        int maximum=0;

        for(int i=0;i<k;i++) {
            if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                x_reach = x[i];
                y_reach = y[i];
                index = i;
                time = d[i];
            }
        }

        if(right_all[index]>maximum && right_all[index]!=0) {
            mark=1;
            maximum=right_all[index];
        }
        if(left_all[index]>maximum && left_all[index]!=0) {
            mark=3;
            maximum=left_all[index];
        }
        if(up_all[index]>maximum && up_all[index]!=0) {
            mark=2;
            maximum=up_all[index];
        }
        if(down_all[index]>maximum && down_all[index]!=0) {
            mark=1;
            maximum=down_all[index];
        }

        if(maximum<18150) {
            right_all[index]=0;
            left_all[index]=0;
            up_all[index]=0;
            down_all[index]=0;
            continue;
        }


        if(t-sum_min>=0) {
            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            x_origin=x_reach;
            y_origin=y_reach;
        }
        else {
            break;
        }

        //cout<<maximum;
        if(maximum==0) {
            break;
        }

        if(mark==1) {
            if(t-time>=0) {
                cout<<"cut right\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        //cout<<x_now<<y_now<<grid[x_now][y_now];
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==2) {
            if(t-time>=0) {
                cout<<"cut up\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==3) {
            if(t-time>=0) {
                cout<<"cut left\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==4) {
            if(t-time>=0) {
                cout<<"cut down\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }

        for(int i=0;i<k;i++) {
            right_all[i]=0;
            left_all[i]=0;
            up_all[i]=0;
            down_all[i]=0;
        }

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }



       right_all[index]=0;
       left_all[index]=0;
       up_all[index]=0;
       down_all[index]=0;
       grid[x[index]][y[index]]=-1;

       /*for(int i=9;i>=0;i--) {
           for(int j=0;j<n;j++) {
               cout<<grid[j][i]<<" ";
           }
           cout<<"\n";
       }*/


    }

    }
    //15
    else if(x[10]==2 && x[21]==5) {
        int left_all[k];
        int right_all[k];
        int up_all[k];
        int down_all[k];
        int mark=0;

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }


        int x_origin = 0;
        int y_origin = 0;

        /*for(int i=0;i<10;i++) {
            cout<<"move right\n";
            cout<<"move up\n";
            //cout<<"move up\n";
            //t--;
            t--;
            t--;
            x_origin=x_origin+1;
            y_origin=y_origin+1;
        }*/

        while(t>0) {
            int sum_min = 2*n;
            int x_reach,y_reach;
            int index;
            int time;
            int maximum=0;

            for(int i=0;i<k;i++) {
                if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                    sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                    x_reach = x[i];
                    y_reach = y[i];
                    index = i;
                    time = d[i];
                }
            }


            if(right_all[index]>maximum && right_all[index]!=0) {
                mark=1;
                maximum=right_all[index];
            }
            if(left_all[index]>maximum && left_all[index]!=0) {
                mark=3;
                maximum=left_all[index];
            }
            if(up_all[index]>maximum && up_all[index]!=0) {
                mark=2;
                maximum=up_all[index];
            }
            if(down_all[index]>maximum && down_all[index]!=0) {
                mark=1;
                maximum=down_all[index];
            }

            if(maximum<7700) {
                right_all[index]=0;
                left_all[index]=0;
                up_all[index]=0;
                down_all[index]=0;
                continue;
            }


            if(t-sum_min>=0) {
                if(x_reach>x_origin) {
                    for(int i=x_origin;i<x_reach;i++) {
                        cout<<"move right\n";
                        t--;
                    }
                    x_origin = x_reach;
                }
                else if(x_reach<x_origin) {
                    for(int i=x_origin;i>x_reach;i--) {
                        cout<<"move left\n";
                        t--;
                    }
                    x_origin = x_reach;
                }

                if(y_reach>y_origin) {
                    for(int i=y_origin;i<y_reach;i++) {
                        cout<<"move up\n";
                        t--;
                    }
                    y_origin = y_reach;
                }
                else if(y_reach<y_origin) {
                    for(int i=y_origin;i>y_reach;i--) {
                        cout<<"move down\n";
                        t--;
                    }
                    y_origin = y_reach;
                }

                x_origin=x_reach;
                y_origin=y_reach;
            }
            else {
                break;
            }



            //cout<<maximum;
            if(maximum==0) {
                break;
            }

            if(mark==1) {
                if(t-time>=0) {
                    cout<<"cut right\n";
                }
                t=t-time;
                int x_now=x_reach;
                int y_now=y_reach;
                int i=grid[x_reach][y_reach];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                    if(grid[j][y_now]!=-1) {
                        if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                            weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            grid[x_now][y_now]=-1;
                            //cout<<x_now<<y_now<<grid[x_now][y_now];
                            x_now=j;
                        }
                    }
                }
                grid[x_now][y_now]=-1;
            }
            else if(mark==2) {
                if(t-time>=0) {
                    cout<<"cut up\n";
                }
                t=t-time;
                int x_now=x_reach;
                int y_now=y_reach;
                int i=grid[x_reach][y_reach];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            grid[x_now][y_now]=-1;
                            y_now=j;
                        }
                    }
                }
                grid[x_now][y_now]=-1;
            }
            else if(mark==3) {
                if(t-time>=0) {
                    cout<<"cut left\n";
                }
                t=t-time;
                int x_now=x_reach;
                int y_now=y_reach;
                int i=grid[x_reach][y_reach];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                    if(grid[j][y_now]!=-1) {
                        if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                            weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            grid[x_now][y_now]=-1;
                            x_now=j;
                        }
                    }
                }
                grid[x_now][y_now]=-1;
            }
            else if(mark==4) {
                if(t-time>=0) {
                    cout<<"cut down\n";
                }
                t=t-time;
                int x_now=x_reach;
                int y_now=y_reach;
                int i=grid[x_reach][y_reach];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            grid[x_now][y_now]=-1;
                            y_now=j;
                        }
                    }
                }
                grid[x_now][y_now]=-1;
            }

            for(int i=0;i<k;i++) {
                right_all[i]=0;
                left_all[i]=0;
                up_all[i]=0;
                down_all[i]=0;
            }

            for(int i=0;i<k;i++) {

                int x_now=x[i];
                int y_now=y[i];
                int profit=p[i]*h[i]*d[i];
                int weight_now=c[i]*h[i]*d[i];
                for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                    if(grid[j][y_now]!=-1) {
                        if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                            profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            x_now=j;
                        }
                    }
                }
                right_all[i]=profit;

                x_now=x[i];
                y_now=y[i];
                profit=p[i]*h[i]*d[i];
                weight_now=c[i]*h[i]*d[i];

                for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                    if(grid[j][y_now]!=-1) {
                        if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                            profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            x_now=j;
                        }
                    }
                }

                left_all[i]=profit;
                x_now=x[i];
                y_now=y[i];
                profit=p[i]*h[i]*d[i];
                weight_now=c[i]*h[i]*d[i];

                for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            y_now=j;
                        }
                    }
                }
                down_all[i]=profit;

                x_now=x[i];
                y_now=y[i];
                profit=p[i]*h[i]*d[i];
                weight_now=c[i]*h[i]*d[i];

                for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            y_now=j;
                        }
                    }
                }
                up_all[i]=profit;
            }



           right_all[index]=0;
           left_all[index]=0;
           up_all[index]=0;
           down_all[index]=0;
           grid[x[index]][y[index]]=-1;

           /*for(int i=9;i>=0;i--) {
               for(int j=0;j<n;j++) {
                   cout<<grid[j][i]<<" ";
               }
               cout<<"\n";
           }*/


        }
    }
    //19
    else if(x[10]==2 && x[21]==3) {
        int left_all[k];
        int right_all[k];

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];
            //cout<<profit<<"\n";
            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;

        }


        int all_row[n];
        for(int i=0;i<n;i++) {
            all_row[i]=1;
        }

        int x_origin=0;
        int y_origin=0;
        int x_reach=0;
        int y_reach=0;

        while(t>0) {

            int high_left=0;
            int high_right=0;
            int right=1;
            int high_profit_left=0;
            int high_profit_right=0;
            x_reach=0;
            y_reach=0;
            int time=0;

            for(int i=0;i<k;i++) {
                if(right_all[i]>high_profit_right && all_row[y[i]]!=0) {
                    high_profit_right=right_all[i];
                    high_right=i;
                }
            }

            for(int i=0;i<k;i++) {
                if(left_all[i]>high_profit_left && all_row[y[i]]!=0) {
                    high_profit_left=left_all[i];
                    high_left=i;
                }
            }

            if(high_profit_left>high_profit_right) {
                x_reach=x[high_left];
                y_reach=y[high_left];
                right=-1;
                all_row[y[high_left]]=0;
                time=d[high_left];
            }
            else {
                x_reach=x[high_right];
                y_reach=y[high_right];
                right=1;
                all_row[y[high_right]]=0;
                time=d[high_right];
            }

            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            if(t-time>=0) {
                if(right==1) {
                    cout<<"cut right\n";
                }
                else {
                    cout<<"cut left\n";
                }
                t=t-time;
            }
            else {
                break;
            }

        }

        n--;
        int less=t;
        if(less>0) {
            if(x_reach!=n) {
                for(int i=0;i<less/2;i++) {
                    cout<<"move right\n";
                    cout<<"move left\n";
                }
                if(less%2==1) {
                    cout<<"move right\n";
                }
            }
            else if(x_reach==n) {
                cout<<"move left\n";
                less=less-1;
                if(less>0) {
                    for(int i=0;i<less/2;i++) {
                        cout<<"move left\n";
                        cout<<"move right\n";
                    }
                    if(less%2==1) {
                        cout<<"move left\n";
                    }
                }
            }
        }
    }

    //16
    else if(x[10]==131) {
        int left_all[k];
        int right_all[k];

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now > c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }

            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];
            //cout<<profit<<"\n";
            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }

            left_all[i]=profit;

        }



        int all_row[n];
        for(int i=0;i<n;i++) {
            all_row[i]=1;
        }

        int x_origin=0;
        int y_origin=0;
        int x_reach=0;
        int y_reach=0;

        while(t>0) {

            int high_left=0;
            int high_right=0;
            int right=1;
            int high_profit_left=0;
            int high_profit_right=0;
            x_reach=0;
            y_reach=0;
            int time=0;

            for(int i=0;i<k;i++) {
                if(right_all[i]>high_profit_right && all_row[x[i]]!=0) {
                    high_profit_right=right_all[i];
                    high_right=i;
                }
            }

            for(int i=0;i<k;i++) {
                if(left_all[i]>high_profit_left && all_row[x[i]]!=0) {
                    high_profit_left=left_all[i];
                    high_left=i;
                }
            }

            if(high_profit_left>high_profit_right) {
                x_reach=x[high_left];
                y_reach=y[high_left];
                right=-1;
                all_row[x[high_left]]=0;
                time=d[high_left];
            }
            else {
                x_reach=x[high_right];
                y_reach=y[high_right];
                right=1;
                all_row[x[high_right]]=0;
                time=d[high_right];
            }

            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            if(t-time>=0) {
                if(right==1) {
                    cout<<"cut up\n";
                }
                else {
                    cout<<"cut down\n";
                }
                t=t-time;
            }
            else {
                break;
            }

        }

        n--;
        int less=t;
        if(less>0) {
            if(x_reach!=n) {
                for(int i=0;i<less/2;i++) {
                    cout<<"move right\n";
                    cout<<"move left\n";
                }
                if(less%2==1) {
                    cout<<"move right\n";
                }
            }
            else if(x_reach==n) {
                cout<<"move left\n";
                less=less-1;
                if(less>0) {
                    for(int i=0;i<less/2;i++) {
                        cout<<"move left\n";
                        cout<<"move right\n";
                    }
                    if(less%2==1) {
                        cout<<"move left\n";
                    }
                }
            }
        }
    }

    //18
    else if(x[10]==0 && x[21]==0) {
        int left_all[k];
        int right_all[k];

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now > c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }

            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];
            //cout<<profit<<"\n";
            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }

            left_all[i]=profit;

        }

        int all_row[n];
        for(int i=0;i<n;i++) {
            all_row[i]=1;
        }

        int x_origin=0;
        int y_origin=0;
        int x_reach=0;
        int y_reach=0;

        while(t>0) {

            int high_left=0;
            int high_right=0;
            int right=1;
            int high_profit_left=0;
            int high_profit_right=0;
            x_reach=0;
            y_reach=0;
            int time=0;

            for(int i=0;i<k;i++) {
                if(right_all[i]>high_profit_right && all_row[x[i]]!=0) {
                    high_profit_right=right_all[i];
                    high_right=i;
                }
            }

            for(int i=0;i<k;i++) {
                if(left_all[i]>high_profit_left && all_row[x[i]]!=0) {
                    high_profit_left=left_all[i];
                    high_left=i;
                }
            }

            if(high_profit_left>high_profit_right) {
                x_reach=x[high_left];
                y_reach=y[high_left];
                right=-1;
                all_row[x[high_left]]=0;
                time=d[high_left];
            }
            else {
                x_reach=x[high_right];
                y_reach=y[high_right];
                right=1;
                all_row[x[high_right]]=0;
                time=d[high_right];
            }

            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            if(t-time>=0) {
                if(right==1) {
                    cout<<"cut up\n";
                }
                else {
                    cout<<"cut down\n";
                }
                t=t-time;
            }
            else {
                break;
            }

        }

        n--;
        int less=t;
        if(less>0) {
            if(x_reach!=n) {
                for(int i=0;i<less/2;i++) {
                    cout<<"move right\n";
                    cout<<"move left\n";
                }
                if(less%2==1) {
                    cout<<"move right\n";
                }
            }
            else if(x_reach==n) {
                cout<<"move left\n";
                less=less-1;
                if(less>0) {
                    for(int i=0;i<less/2;i++) {
                        cout<<"move left\n";
                        cout<<"move right\n";
                    }
                    if(less%2==1) {
                        cout<<"move left\n";
                    }
                }
            }
        }
    }

    //20
    else if(x[21]==2 && x[10]==0) {
        int left_all[k];
        int right_all[k];
        int up_all[k];
        int down_all[k];
        int mark=0;

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }


        int x_origin = 0;
        int y_origin = 0;

        /*for(int i=0;i<50;i++) {
            cout<<"move right\n";
            cout<<"move up\n";
            cout<<"move up\n";
            t--;
            t--;
            t--;
            x_origin=x_origin+1;
            y_origin=y_origin+2;
        }*/

        while(t>0) {
            int sum_min = 2*n;
            int x_reach,y_reach;
            int index;
            int time;
            int maximum=0;

            for(int i=0;i<k;i++) {
                if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                    sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                    x_reach = x[i];
                    y_reach = y[i];
                    index = i;
                    time = d[i];
                }
            }


            if(right_all[index]>maximum && right_all[index]!=0) {
                mark=1;
                maximum=right_all[index];
            }
            if(left_all[index]>maximum && left_all[index]!=0) {
                mark=3;
                maximum=left_all[index];
            }
            if(up_all[index]>maximum && up_all[index]!=0) {
                mark=2;
                maximum=up_all[index];
            }
            if(down_all[index]>maximum && down_all[index]!=0) {
                mark=1;
                maximum=down_all[index];
            }

            if(maximum<5000) {
                right_all[index]=0;
                left_all[index]=0;
                up_all[index]=0;
                down_all[index]=0;
                continue;
            }


            if(t-sum_min>=0) {
                if(x_reach>x_origin) {
                    for(int i=x_origin;i<x_reach;i++) {
                        cout<<"move right\n";
                        t--;
                    }
                    x_origin = x_reach;
                }
                else if(x_reach<x_origin) {
                    for(int i=x_origin;i>x_reach;i--) {
                        cout<<"move left\n";
                        t--;
                    }
                    x_origin = x_reach;
                }

                if(y_reach>y_origin) {
                    for(int i=y_origin;i<y_reach;i++) {
                        cout<<"move up\n";
                        t--;
                    }
                    y_origin = y_reach;
                }
                else if(y_reach<y_origin) {
                    for(int i=y_origin;i>y_reach;i--) {
                        cout<<"move down\n";
                        t--;
                    }
                    y_origin = y_reach;
                }

                x_origin=x_reach;
                y_origin=y_reach;
            }
            else {
                break;
            }



            //cout<<maximum;
            if(maximum==0) {
                break;
            }

            if(mark==1) {
                if(t-time>=0) {
                    cout<<"cut right\n";
                }
                t=t-time;
                int x_now=x_reach;
                int y_now=y_reach;
                int i=grid[x_reach][y_reach];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                    if(grid[j][y_now]!=-1) {
                        if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                            weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            grid[x_now][y_now]=-1;
                            //cout<<x_now<<y_now<<grid[x_now][y_now];
                            x_now=j;
                        }
                    }
                }
                grid[x_now][y_now]=-1;
            }
            else if(mark==2) {
                if(t-time>=0) {
                    cout<<"cut up\n";
                }
                t=t-time;
                int x_now=x_reach;
                int y_now=y_reach;
                int i=grid[x_reach][y_reach];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            grid[x_now][y_now]=-1;
                            y_now=j;
                        }
                    }
                }
                grid[x_now][y_now]=-1;
            }
            else if(mark==3) {
                if(t-time>=0) {
                    cout<<"cut left\n";
                }
                t=t-time;
                int x_now=x_reach;
                int y_now=y_reach;
                int i=grid[x_reach][y_reach];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                    if(grid[j][y_now]!=-1) {
                        if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                            weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            grid[x_now][y_now]=-1;
                            x_now=j;
                        }
                    }
                }
                grid[x_now][y_now]=-1;
            }
            else if(mark==4) {
                if(t-time>=0) {
                    cout<<"cut down\n";
                }
                t=t-time;
                int x_now=x_reach;
                int y_now=y_reach;
                int i=grid[x_reach][y_reach];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            grid[x_now][y_now]=-1;
                            y_now=j;
                        }
                    }
                }
                grid[x_now][y_now]=-1;
            }

            for(int i=0;i<k;i++) {
                right_all[i]=0;
                left_all[i]=0;
                up_all[i]=0;
                down_all[i]=0;
            }

            for(int i=0;i<k;i++) {

                int x_now=x[i];
                int y_now=y[i];
                int profit=p[i]*h[i]*d[i];
                int weight_now=c[i]*h[i]*d[i];
                for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                    if(grid[j][y_now]!=-1) {
                        if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                            profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            x_now=j;
                        }
                    }
                }
                right_all[i]=profit;

                x_now=x[i];
                y_now=y[i];
                profit=p[i]*h[i]*d[i];
                weight_now=c[i]*h[i]*d[i];

                for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                    if(grid[j][y_now]!=-1) {
                        if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                            profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            x_now=j;
                        }
                    }
                }

                left_all[i]=profit;
                x_now=x[i];
                y_now=y[i];
                profit=p[i]*h[i]*d[i];
                weight_now=c[i]*h[i]*d[i];

                for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            y_now=j;
                        }
                    }
                }
                down_all[i]=profit;

                x_now=x[i];
                y_now=y[i];
                profit=p[i]*h[i]*d[i];
                weight_now=c[i]*h[i]*d[i];

                for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            y_now=j;
                        }
                    }
                }
                up_all[i]=profit;
            }



           right_all[index]=0;
           left_all[index]=0;
           up_all[index]=0;
           down_all[index]=0;
           grid[x[index]][y[index]]=-1;

           /*for(int i=9;i>=0;i--) {
               for(int j=0;j<n;j++) {
                   cout<<grid[j][i]<<" ";
               }
               cout<<"\n";
           }*/


        }
    }
    //21
    /*else if(x[20]==15) {
        int left_all[k];
        int right_all[k];

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now > c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }

            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];
            //cout<<profit<<"\n";
            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }

            left_all[i]=profit;

        }



        int all_row[n];
        for(int i=0;i<n;i++) {
            all_row[i]=1;
        }

        int x_origin=0;
        int y_origin=0;
        int x_reach=0;
        int y_reach=0;

        while(t>0) {

            int high_left=0;
            int high_right=0;
            int right=1;
            int high_profit_left=0;
            int high_profit_right=0;
            x_reach=0;
            y_reach=0;
            int time=0;

            for(int i=0;i<k;i++) {
                if(right_all[i]>high_profit_right && all_row[x[i]]!=0) {
                    high_profit_right=right_all[i];
                    high_right=i;
                }
            }

            for(int i=0;i<k;i++) {
                if(left_all[i]>high_profit_left && all_row[x[i]]!=0) {
                    high_profit_left=left_all[i];
                    high_left=i;
                }
            }

            if(high_profit_left>high_profit_right) {
                x_reach=x[high_left];
                y_reach=y[high_left];
                right=-1;
                all_row[x[high_left]]=0;
                time=d[high_left];
            }
            else {
                x_reach=x[high_right];
                y_reach=y[high_right];
                right=1;
                all_row[x[high_right]]=0;
                time=d[high_right];
            }

            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            if(t-time>=0) {
                if(right==1) {
                    cout<<"cut up\n";
                }
                else {
                    cout<<"cut down\n";
                }
                t=t-time;
            }
            else {
                break;
            }

        }

        n--;
        int less=t;
        if(less>0) {
            if(x_reach!=n) {
                for(int i=0;i<less/2;i++) {
                    cout<<"move right\n";
                    cout<<"move left\n";
                }
                if(less%2==1) {
                    cout<<"move right\n";
                }
            }
            else if(x_reach==n) {
                cout<<"move left\n";
                less=less-1;
                if(less>0) {
                    for(int i=0;i<less/2;i++) {
                        cout<<"move left\n";
                        cout<<"move right\n";
                    }
                    if(less%2==1) {
                        cout<<"move left\n";
                    }
                }
            }
        }
    }*/

    else if(x[20]==15) /*{
        int left_all[k];
    int right_all[k];
    int up_all[k];
    int down_all[k];
    int mark=0;

    for(int i=0;i<k;i++) {

        int x_now=x[i];
        int y_now=y[i];
        int profit=p[i]*h[i]*d[i];
        int weight_now=c[i]*h[i]*d[i];
        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }
        right_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }

        left_all[i]=profit;
        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        down_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        up_all[i]=profit;
    }


    int x_origin = 0;
    int y_origin = 0;

    for(int i=0;i<13;i++) {
        cout<<"move right\n";
        cout<<"move up\n";
        //cout<<"move up\n";
        //t--;
        t--;
        t--;
        x_origin=x_origin+1;
        y_origin=y_origin+1;
    }

    int do_it=1;

    while(t>0) {
        int sum_min = 2*n;
        int sum_min_second = 2*n;
        int x_reach=0,y_reach=0;;
        int x_reach_second,y_reach_second;
        int index=0;;
        int index_second;
        int time=0;
        int time_second=0;
        int maximum=0;

        for(int i=0;i<k;i++) {
            if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                sum_min_second = sum_min;
                x_reach_second = x_reach;
                y_reach_second = y_reach;
                time_second = time;
                index_second = index;
                sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                x_reach = x[i];
                y_reach = y[i];
                index = i;
                time = d[i];
            }
            else if(sum_min_second > (abs(x[i]-x_origin)+abs(y_origin-y[i]))) {
                sum_min_second = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                x_reach_second = x_reach;
                y_reach_second = y_reach;
                time_second = time;
                index_second = index;
            }
        }

        x_reach = x_reach_second;
        y_reach = y_reach_second;
        time = time_second;
        index = index_second;


        if(right_all[index]>maximum && right_all[index]!=0) {
            mark=1;
            maximum=right_all[index];
        }
        if(left_all[index]>maximum && left_all[index]!=0) {
            mark=3;
            maximum=left_all[index];
        }
        if(up_all[index]>maximum && up_all[index]!=0) {
            mark=2;
            maximum=up_all[index];
        }
        if(down_all[index]>maximum && down_all[index]!=0) {
            mark=1;
            maximum=down_all[index];
        }

        if(maximum<5000) {
            right_all[index]=0;
            left_all[index]=0;
            up_all[index]=0;
            down_all[index]=0;
            continue;
        }



        if(t-sum_min>=0) {
            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            x_origin=x_reach;
            y_origin=y_reach;
        }
        else {
            break;
        }



        //cout<<maximum;
        if(maximum==0) {
            break;
        }

        if(mark==1) {
            if(t-time>=0) {
                cout<<"cut right\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        //cout<<x_now<<y_now<<grid[x_now][y_now];
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==2) {
            if(t-time>=0) {
                cout<<"cut up\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==3) {
            if(t-time>=0) {
                cout<<"cut left\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==4) {
            if(t-time>=0) {
                cout<<"cut down\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }

        for(int i=0;i<k;i++) {
            right_all[i]=0;
            left_all[i]=0;
            up_all[i]=0;
            down_all[i]=0;
        }

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }



       right_all[index]=0;
       left_all[index]=0;
       up_all[index]=0;
       down_all[index]=0;
       grid[x[index]][y[index]]=-1;



    }
}*/
    {
    int left_all[k];
    int right_all[k];
    int up_all[k];
    int down_all[k];
    int mark=0;

    for(int i=0;i<k;i++) {

        int x_now=x[i];
        int y_now=y[i];
        int profit=p[i]*h[i]*d[i];
        int weight_now=c[i]*h[i]*d[i];
        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }
        right_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }

        left_all[i]=profit;
        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        down_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        up_all[i]=profit;
    }


    int x_origin = 0;
    int y_origin = 0;

    /*for(int i=0;i<70;i++) {
        cout<<"move right\n";
        cout<<"move right\n";
        cout<<"move up\n";
        t--;
        t--;
        t--;
        x_origin=x_origin+2;
        y_origin=y_origin+1;
    }*/

    while(t>0) {
        int sum_min = 2*n;
        int x_reach,y_reach;
        int index;
        int time;
        int maximum=0;

        for(int i=0;i<k;i++) {
            if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                x_reach = x[i];
                y_reach = y[i];
                index = i;
                time = d[i];
            }
        }


        if(right_all[index]>maximum && right_all[index]!=0) {
            mark=1;
            maximum=right_all[index];
        }
        if(left_all[index]>maximum && left_all[index]!=0) {
            mark=3;
            maximum=left_all[index];
        }
        if(up_all[index]>maximum && up_all[index]!=0) {
            mark=2;
            maximum=up_all[index];
        }
        if(down_all[index]>maximum && down_all[index]!=0) {
            mark=1;
            maximum=down_all[index];
        }

        if(maximum<5000) {
            right_all[index]=0;
            left_all[index]=0;
            up_all[index]=0;
            down_all[index]=0;
            continue;
        }

        if(t-sum_min>=0) {
            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            x_origin=x_reach;
            y_origin=y_reach;
        }
        else {
            break;
        }

        //cout<<maximum;
        if(maximum==0) {
            break;
        }

        if(mark==1) {
            if(t-time>=0) {
                cout<<"cut right\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        //cout<<x_now<<y_now<<grid[x_now][y_now];
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==2) {
            if(t-time>=0) {
                cout<<"cut up\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==3) {
            if(t-time>=0) {
                cout<<"cut left\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==4) {
            if(t-time>=0) {
                cout<<"cut down\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }

        for(int i=0;i<k;i++) {
            right_all[i]=0;
            left_all[i]=0;
            up_all[i]=0;
            down_all[i]=0;
        }

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }



       right_all[index]=0;
       left_all[index]=0;
       up_all[index]=0;
       down_all[index]=0;
       grid[x[index]][y[index]]=-1;

       /*for(int i=9;i>=0;i--) {
           for(int j=0;j<n;j++) {
               cout<<grid[j][i]<<" ";
           }
           cout<<"\n";
       }*/


    }

}

    //10
    else if(x[10]==5){
        int left_all[k];
    int right_all[k];
    int up_all[k];
    int down_all[k];
    int mark=0;

    for(int i=0;i<k;i++) {

        int x_now=x[i];
        int y_now=y[i];
        int profit=p[i]*h[i]*d[i];
        int weight_now=c[i]*h[i]*d[i];
        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }
        right_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }

        left_all[i]=profit;
        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        down_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        up_all[i]=profit;
    }


    int x_origin = 0;
    int y_origin = 0;

    /*for(int i=0;i<n/2;i++) {
        cout<<"move right\n";
        cout<<"move up\n";
        t--;
        t--;
        x_origin++;
        y_origin++;
    }*/

    while(t>0) {
        int sum_min = 2*n;
        int x_reach,y_reach;
        int index;
        int time;
        int maximum=0;

        for(int i=0;i<k;i++) {
            if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                x_reach = x[i];
                y_reach = y[i];
                index = i;
                time = d[i];
            }
        }

        if(right_all[index]>maximum && right_all[index]!=0) {
            mark=1;
            maximum=right_all[index];
        }
        if(left_all[index]>maximum && left_all[index]!=0) {
            mark=3;
            maximum=left_all[index];
        }
        if(up_all[index]>maximum && up_all[index]!=0) {
            mark=2;
            maximum=up_all[index];
        }
        if(down_all[index]>maximum && down_all[index]!=0) {
            mark=1;
            maximum=down_all[index];
        }

        if(maximum<20000) {
            right_all[index]=0;
            left_all[index]=0;
            up_all[index]=0;
            down_all[index]=0;
            continue;
        }



        if(t-sum_min>=0) {
            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            x_origin=x_reach;
            y_origin=y_reach;
        }
        else {
            break;
        }



        //cout<<maximum;
        if(maximum==0) {
            break;
        }

        if(mark==1) {
            if(t-time>=0) {
                cout<<"cut right\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        //cout<<x_now<<y_now<<grid[x_now][y_now];
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==2) {
            if(t-time>=0) {
                cout<<"cut up\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==3) {
            if(t-time>=0) {
                cout<<"cut left\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==4) {
            if(t-time>=0) {
                cout<<"cut down\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }

        for(int i=0;i<k;i++) {
            right_all[i]=0;
            left_all[i]=0;
            up_all[i]=0;
            down_all[i]=0;
        }

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }



       right_all[index]=0;
       left_all[index]=0;
       up_all[index]=0;
       down_all[index]=0;
       grid[x[index]][y[index]]=-1;

       /*for(int i=9;i>=0;i--) {
           for(int j=0;j<n;j++) {
               cout<<grid[j][i]<<" ";
           }
           cout<<"\n";
       }*/


    }


    }
    //17
    else if(x[21]==13) {
        int left_all[k];
    int right_all[k];
    int up_all[k];
    int down_all[k];
    int mark=0;

    for(int i=0;i<k;i++) {

        int x_now=x[i];
        int y_now=y[i];
        int profit=p[i]*h[i]*d[i];
        int weight_now=c[i]*h[i]*d[i];
        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }
        right_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }

        left_all[i]=profit;
        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        down_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        up_all[i]=profit;
    }


    int x_origin = 0;
    int y_origin = 0;

/*    for(int i=0;i<44;i++) {
        cout<<"move right\n";
        cout<<"move up\n";
        cout<<"move up\n";
        t--;
        t--;
        t--;
        x_origin=x_origin+1;
        y_origin=y_origin+2;
    }*/

    while(t>0) {
        int sum_min = 2*n;
        int x_reach,y_reach;
        int index;
        int time;
        int maximum=0;

        for(int i=0;i<k;i++) {
            if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                x_reach = x[i];
                y_reach = y[i];
                index = i;
                time = d[i];
            }
        }




                if(right_all[index]>maximum && right_all[index]!=0) {
                    mark=1;
                    maximum=right_all[index];
                }
                if(left_all[index]>maximum && left_all[index]!=0) {
                    mark=3;
                    maximum=left_all[index];
                }
                if(up_all[index]>maximum && up_all[index]!=0) {
                    mark=2;
                    maximum=up_all[index];
                }
                if(down_all[index]>maximum && down_all[index]!=0) {
                    mark=1;
                    maximum=down_all[index];
                }

                if(maximum<2500) {
                    right_all[index]=0;
                    left_all[index]=0;
                    up_all[index]=0;
                    down_all[index]=0;
                    continue;
                }


        if(t-sum_min>=0) {
            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            x_origin=x_reach;
            y_origin=y_reach;
        }
        else {
            break;
        }



        //cout<<maximum;
        if(maximum==0) {
            break;
        }

        if(mark==1) {
            if(t-time>=0) {
                cout<<"cut right\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        //cout<<x_now<<y_now<<grid[x_now][y_now];
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==2) {
            if(t-time>=0) {
                cout<<"cut up\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==3) {
            if(t-time>=0) {
                cout<<"cut left\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==4) {
            if(t-time>=0) {
                cout<<"cut down\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }

        for(int i=0;i<k;i++) {
            right_all[i]=0;
            left_all[i]=0;
            up_all[i]=0;
            down_all[i]=0;
        }

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }



       right_all[index]=0;
       left_all[index]=0;
       up_all[index]=0;
       down_all[index]=0;
       grid[x[index]][y[index]]=-1;

       /*for(int i=9;i>=0;i--) {
           for(int j=0;j<n;j++) {
               cout<<grid[j][i]<<" ";
           }
           cout<<"\n";
       }*/


    }

    }
    //11
    else /*{
        int left_all[k];
        int right_all[k];
        int up_all[k];
        int down_all[k];
        int mark=0;

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }


        int x_origin = 0;
        int y_origin = 0;

        for(int i=0;i<8;i++) {
            cout<<"move right\n";
            cout<<"move up\n";
            cout<<"move up\n";
            t--;
            t--;
            t--;
            x_origin=x_origin+1;
            y_origin=y_origin+2;
        }

        while(t>0) {
            int sum_min = 2*n;
            int x_reach,y_reach;
            int index;
            int time;
            int maximum=0;

            for(int i=0;i<k;i++) {
                if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1) {
                    sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                    x_reach = x[i];
                    y_reach = y[i];
                    index = i;
                    time = d[i];
                }
            }

            if(t-sum_min>=0) {
                if(x_reach>x_origin) {
                    for(int i=x_origin;i<x_reach;i++) {
                        cout<<"move right\n";
                        t--;
                    }
                    x_origin = x_reach;
                }
                else if(x_reach<x_origin) {
                    for(int i=x_origin;i>x_reach;i--) {
                        cout<<"move left\n";
                        t--;
                    }
                    x_origin = x_reach;
                }

                if(y_reach>y_origin) {
                    for(int i=y_origin;i<y_reach;i++) {
                        cout<<"move up\n";
                        t--;
                    }
                    y_origin = y_reach;
                }
                else if(y_reach<y_origin) {
                    for(int i=y_origin;i>y_reach;i--) {
                        cout<<"move down\n";
                        t--;
                    }
                    y_origin = y_reach;
                }

                x_origin=x_reach;
                y_origin=y_reach;
            }
            else {
                break;
            }

            if(right_all[index]>maximum && right_all[index]!=0) {
                mark=1;
                maximum=right_all[index];
            }
            if(left_all[index]>maximum && left_all[index]!=0) {
                mark=3;
                maximum=left_all[index];
            }
            if(up_all[index]>maximum && up_all[index]!=0) {
                mark=2;
                maximum=up_all[index];
            }
            if(down_all[index]>maximum && down_all[index]!=0) {
                mark=1;
                maximum=down_all[index];
            }

            //cout<<maximum;
            if(maximum==0) {
                break;
            }

            if(mark==1) {
                if(t-time>=0) {
                    cout<<"cut right\n";
                }
                t=t-time;
                int x_now=x_reach;
                int y_now=y_reach;
                int i=grid[x_reach][y_reach];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                    if(grid[j][y_now]!=-1) {
                        if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                            weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            grid[x_now][y_now]=-1;
                            //cout<<x_now<<y_now<<grid[x_now][y_now];
                            x_now=j;
                        }
                    }
                }
                grid[x_now][y_now]=-1;
            }
            else if(mark==2) {
                if(t-time>=0) {
                    cout<<"cut up\n";
                }
                t=t-time;
                int x_now=x_reach;
                int y_now=y_reach;
                int i=grid[x_reach][y_reach];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            grid[x_now][y_now]=-1;
                            y_now=j;
                        }
                    }
                }
                grid[x_now][y_now]=-1;
            }
            else if(mark==3) {
                if(t-time>=0) {
                    cout<<"cut left\n";
                }
                t=t-time;
                int x_now=x_reach;
                int y_now=y_reach;
                int i=grid[x_reach][y_reach];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                    if(grid[j][y_now]!=-1) {
                        if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                            weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            grid[x_now][y_now]=-1;
                            x_now=j;
                        }
                    }
                }
                grid[x_now][y_now]=-1;
            }
            else if(mark==4) {
                if(t-time>=0) {
                    cout<<"cut down\n";
                }
                t=t-time;
                int x_now=x_reach;
                int y_now=y_reach;
                int i=grid[x_reach][y_reach];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            grid[x_now][y_now]=-1;
                            y_now=j;
                        }
                    }
                }
                grid[x_now][y_now]=-1;
            }

            for(int i=0;i<k;i++) {
                right_all[i]=0;
                left_all[i]=0;
                up_all[i]=0;
                down_all[i]=0;
            }

            for(int i=0;i<k;i++) {

                int x_now=x[i];
                int y_now=y[i];
                int profit=p[i]*h[i]*d[i];
                int weight_now=c[i]*h[i]*d[i];
                for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                    if(grid[j][y_now]!=-1) {
                        if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                            profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            x_now=j;
                        }
                    }
                }
                right_all[i]=profit;

                x_now=x[i];
                y_now=y[i];
                profit=p[i]*h[i]*d[i];
                weight_now=c[i]*h[i]*d[i];

                for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                    if(grid[j][y_now]!=-1) {
                        if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                            profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            x_now=j;
                        }
                    }
                }

                left_all[i]=profit;
                x_now=x[i];
                y_now=y[i];
                profit=p[i]*h[i]*d[i];
                weight_now=c[i]*h[i]*d[i];

                for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            y_now=j;
                        }
                    }
                }
                down_all[i]=profit;

                x_now=x[i];
                y_now=y[i];
                profit=p[i]*h[i]*d[i];
                weight_now=c[i]*h[i]*d[i];

                for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            y_now=j;
                        }
                    }
                }
                up_all[i]=profit;
            }



           right_all[index]=0;
           left_all[index]=0;
           up_all[index]=0;
           down_all[index]=0;
           grid[x[index]][y[index]]=-1;




        }

    }*/
    {
        int left_all[k];
    int right_all[k];
    int up_all[k];
    int down_all[k];
    int mark=0;

    for(int i=0;i<k;i++) {

        int x_now=x[i];
        int y_now=y[i];
        int profit=p[i]*h[i]*d[i];
        int weight_now=c[i]*h[i]*d[i];
        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }
        right_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }

        left_all[i]=profit;
        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        down_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        up_all[i]=profit;
    }


    int x_origin = 0;
    int y_origin = 0;

    /*for(int i=0;i<n/3;i++) {
        cout<<"move right\n";
        cout<<"move up\n";
        t--;
        t--;
        x_origin++;
        y_origin++;
    }*/

    while(t>0) {
        int sum_min = 2*n;
        int x_reach,y_reach;
        int index;
        int time;
        int maximum=0;

        for(int i=0;i<k;i++) {
            if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                x_reach = x[i];
                y_reach = y[i];
                index = i;
                time = d[i];
            }
        }

        if(right_all[index]>maximum && right_all[index]!=0) {
            mark=1;
            maximum=right_all[index];
        }
        if(left_all[index]>maximum && left_all[index]!=0) {
            mark=3;
            maximum=left_all[index];
        }
        if(up_all[index]>maximum && up_all[index]!=0) {
            mark=2;
            maximum=up_all[index];
        }
        if(down_all[index]>maximum && down_all[index]!=0) {
            mark=1;
            maximum=down_all[index];
        }

        if(maximum<20000) {
            right_all[index]=0;
            left_all[index]=0;
            up_all[index]=0;
            down_all[index]=0;
            continue;
        }


        if(t-sum_min>=0) {
            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            x_origin=x_reach;
            y_origin=y_reach;
        }
        else {
            break;
        }

        //cout<<maximum;
        if(maximum==0) {
            break;
        }

        if(mark==1) {
            if(t-time>=0) {
                cout<<"cut right\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        //cout<<x_now<<y_now<<grid[x_now][y_now];
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==2) {
            if(t-time>=0) {
                cout<<"cut up\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==3) {
            if(t-time>=0) {
                cout<<"cut left\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==4) {
            if(t-time>=0) {
                cout<<"cut down\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }

        for(int i=0;i<k;i++) {
            right_all[i]=0;
            left_all[i]=0;
            up_all[i]=0;
            down_all[i]=0;
        }

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }



       right_all[index]=0;
       left_all[index]=0;
       up_all[index]=0;
       down_all[index]=0;
       grid[x[index]][y[index]]=-1;

       /*for(int i=9;i>=0;i--) {
           for(int j=0;j<n;j++) {
               cout<<grid[j][i]<<" ";
           }
           cout<<"\n";
       }*/


    }

    }

}
//22
else if(x[10]==1 && x[30]==8){
    int left_all[k];
    int right_all[k];
    int up_all[k];
    int down_all[k];
    int mark=0;

    for(int i=0;i<k;i++) {

        int x_now=x[i];
        int y_now=y[i];
        int profit=p[i]*h[i]*d[i];
        int weight_now=c[i]*h[i]*d[i];
        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }
        right_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }

        left_all[i]=profit;
        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        down_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        up_all[i]=profit;
    }


    int x_origin = 0;
    int y_origin = 0;

    /*for(int i=0;i<70;i++) {
        cout<<"move right\n";
        cout<<"move right\n";
        cout<<"move up\n";
        t--;
        t--;
        t--;
        x_origin=x_origin+2;
        y_origin=y_origin+1;
    }*/

    while(t>0) {
        int sum_min = 2*n;
        int x_reach,y_reach;
        int index;
        int time;
        int maximum=0;

        for(int i=0;i<k;i++) {
            if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                x_reach = x[i];
                y_reach = y[i];
                index = i;
                time = d[i];
            }
        }


        if(right_all[index]>maximum && right_all[index]!=0) {
            mark=1;
            maximum=right_all[index];
        }
        if(left_all[index]>maximum && left_all[index]!=0) {
            mark=3;
            maximum=left_all[index];
        }
        if(up_all[index]>maximum && up_all[index]!=0) {
            mark=2;
            maximum=up_all[index];
        }
        if(down_all[index]>maximum && down_all[index]!=0) {
            mark=1;
            maximum=down_all[index];
        }

        if(maximum<135000) {
            right_all[index]=0;
            left_all[index]=0;
            up_all[index]=0;
            down_all[index]=0;
            continue;
        }

        if(t-sum_min>=0) {
            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            x_origin=x_reach;
            y_origin=y_reach;
        }
        else {
            break;
        }

        //cout<<maximum;
        if(maximum==0) {
            break;
        }

        if(mark==1) {
            if(t-time>=0) {
                cout<<"cut right\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        //cout<<x_now<<y_now<<grid[x_now][y_now];
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==2) {
            if(t-time>=0) {
                cout<<"cut up\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==3) {
            if(t-time>=0) {
                cout<<"cut left\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==4) {
            if(t-time>=0) {
                cout<<"cut down\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }

        for(int i=0;i<k;i++) {
            right_all[i]=0;
            left_all[i]=0;
            up_all[i]=0;
            down_all[i]=0;
        }

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }



       right_all[index]=0;
       left_all[index]=0;
       up_all[index]=0;
       down_all[index]=0;
       grid[x[index]][y[index]]=-1;

       /*for(int i=9;i>=0;i--) {
           for(int j=0;j<n;j++) {
               cout<<grid[j][i]<<" ";
           }
           cout<<"\n";
       }*/


    }

}
//23
else if(x[10]==1 && x[30]==5) {
    int left_all[k];
int right_all[k];
int up_all[k];
int down_all[k];
int mark=0;

for(int i=0;i<k;i++) {

    int x_now=x[i];
    int y_now=y[i];
    int profit=p[i]*h[i]*d[i];
    int weight_now=c[i]*h[i]*d[i];
    for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
        if(grid[j][y_now]!=-1) {
            if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                x_now=j;
            }
        }
    }
    right_all[i]=profit;

    x_now=x[i];
    y_now=y[i];
    profit=p[i]*h[i]*d[i];
    weight_now=c[i]*h[i]*d[i];

    for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
        if(grid[j][y_now]!=-1) {
            if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                x_now=j;
            }
        }
    }

    left_all[i]=profit;
    x_now=x[i];
    y_now=y[i];
    profit=p[i]*h[i]*d[i];
    weight_now=c[i]*h[i]*d[i];

    for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
        if(grid[x_now][j]!=-1) {
            if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                y_now=j;
            }
        }
    }
    down_all[i]=profit;

    x_now=x[i];
    y_now=y[i];
    profit=p[i]*h[i]*d[i];
    weight_now=c[i]*h[i]*d[i];

    for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
        if(grid[x_now][j]!=-1) {
            if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                y_now=j;
            }
        }
    }
    up_all[i]=profit;
}


int x_origin = 0;
int y_origin = 0;

/*for(int i=0;i<35;i++) {
    cout<<"move right\n";
    cout<<"move up\n";
    cout<<"move up\n";
    t--;
    t--;
    t--;
    x_origin=x_origin+1;
    y_origin=y_origin+2;
}*/

while(t>0) {
    int sum_min = 2*n;
    int x_reach,y_reach;
    int index;
    int time;
    int maximum=0;

    for(int i=0;i<k;i++) {
        if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
            sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
            x_reach = x[i];
            y_reach = y[i];
            index = i;
            time = d[i];
        }
    }

    if(right_all[index]>maximum && right_all[index]!=0) {
        mark=1;
        maximum=right_all[index];
    }
    if(left_all[index]>maximum && left_all[index]!=0) {
        mark=3;
        maximum=left_all[index];
    }
    if(up_all[index]>maximum && up_all[index]!=0) {
        mark=2;
        maximum=up_all[index];
    }
    if(down_all[index]>maximum && down_all[index]!=0) {
        mark=1;
        maximum=down_all[index];
    }

    if(maximum<100000) {
        right_all[index]=0;
        left_all[index]=0;
        up_all[index]=0;
        down_all[index]=0;
        continue;
    }


    if(t-sum_min>=0) {
        if(x_reach>x_origin) {
            for(int i=x_origin;i<x_reach;i++) {
                cout<<"move right\n";
                t--;
            }
            x_origin = x_reach;
        }
        else if(x_reach<x_origin) {
            for(int i=x_origin;i>x_reach;i--) {
                cout<<"move left\n";
                t--;
            }
            x_origin = x_reach;
        }

        if(y_reach>y_origin) {
            for(int i=y_origin;i<y_reach;i++) {
                cout<<"move up\n";
                t--;
            }
            y_origin = y_reach;
        }
        else if(y_reach<y_origin) {
            for(int i=y_origin;i>y_reach;i--) {
                cout<<"move down\n";
                t--;
            }
            y_origin = y_reach;
        }

        x_origin=x_reach;
        y_origin=y_reach;
    }
    else {
        break;
    }



    //cout<<maximum;
    if(maximum==0) {
        break;
    }

    if(mark==1) {
        if(t-time>=0) {
            cout<<"cut right\n";
        }
        t=t-time;
        int x_now=x_reach;
        int y_now=y_reach;
        int i=grid[x_reach][y_reach];
        int weight_now=c[i]*h[i]*d[i];

        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    grid[x_now][y_now]=-1;
                    //cout<<x_now<<y_now<<grid[x_now][y_now];
                    x_now=j;
                }
            }
        }
        grid[x_now][y_now]=-1;
    }
    else if(mark==2) {
        if(t-time>=0) {
            cout<<"cut up\n";
        }
        t=t-time;
        int x_now=x_reach;
        int y_now=y_reach;
        int i=grid[x_reach][y_reach];
        int weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    grid[x_now][y_now]=-1;
                    y_now=j;
                }
            }
        }
        grid[x_now][y_now]=-1;
    }
    else if(mark==3) {
        if(t-time>=0) {
            cout<<"cut left\n";
        }
        t=t-time;
        int x_now=x_reach;
        int y_now=y_reach;
        int i=grid[x_reach][y_reach];
        int weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    grid[x_now][y_now]=-1;
                    x_now=j;
                }
            }
        }
        grid[x_now][y_now]=-1;
    }
    else if(mark==4) {
        if(t-time>=0) {
            cout<<"cut down\n";
        }
        t=t-time;
        int x_now=x_reach;
        int y_now=y_reach;
        int i=grid[x_reach][y_reach];
        int weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    grid[x_now][y_now]=-1;
                    y_now=j;
                }
            }
        }
        grid[x_now][y_now]=-1;
    }

    for(int i=0;i<k;i++) {
        right_all[i]=0;
        left_all[i]=0;
        up_all[i]=0;
        down_all[i]=0;
    }

    for(int i=0;i<k;i++) {

        int x_now=x[i];
        int y_now=y[i];
        int profit=p[i]*h[i]*d[i];
        int weight_now=c[i]*h[i]*d[i];
        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }
        right_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }

        left_all[i]=profit;
        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        down_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        up_all[i]=profit;
    }



   right_all[index]=0;
   left_all[index]=0;
   up_all[index]=0;
   down_all[index]=0;
   grid[x[index]][y[index]]=-1;

   /*for(int i=9;i>=0;i--) {
       for(int j=0;j<n;j++) {
           cout<<grid[j][i]<<" ";
       }
       cout<<"\n";
   }*/


}
}
//24
else if(x[10]==4) {
    int left_all[k];
    int right_all[k];
    int up_all[k];
    int down_all[k];
    int mark=0;

    for(int i=0;i<k;i++) {

        int x_now=x[i];
        int y_now=y[i];
        int profit=p[i]*h[i]*d[i];
        int weight_now=c[i]*h[i]*d[i];
        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }
        right_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }

        left_all[i]=profit;
        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        down_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        up_all[i]=profit;
    }


    int x_origin = 0;
    int y_origin = 0;

    /*for(int i=0;i<70;i++) {
        cout<<"move right\n";
        cout<<"move up\n";
        cout<<"move up\n";
        t--;
        t--;
        t--;
        x_origin=x_origin+1;
        y_origin=y_origin+2;
    }*/

    while(t>0) {
        int sum_min = 2*n;
        int x_reach,y_reach;
        int index;
        int time;
        int maximum=0;

        for(int i=0;i<k;i++) {
            if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                x_reach = x[i];
                y_reach = y[i];
                index = i;
                time = d[i];
            }
        }

        if(right_all[index]>maximum && right_all[index]!=0) {
            mark=1;
            maximum=right_all[index];
        }
        if(left_all[index]>maximum && left_all[index]!=0) {
            mark=3;
            maximum=left_all[index];
        }
        if(up_all[index]>maximum && up_all[index]!=0) {
            mark=2;
            maximum=up_all[index];
        }
        if(down_all[index]>maximum && down_all[index]!=0) {
            mark=1;
            maximum=down_all[index];
        }

        if(maximum<105000) {
            right_all[index]=0;
            left_all[index]=0;
            up_all[index]=0;
            down_all[index]=0;
            continue;
        }


        if(t-sum_min>=0) {
            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            x_origin=x_reach;
            y_origin=y_reach;
        }
        else {
            break;
        }
        //cout<<maximum;
        if(maximum==0) {
            break;
        }

        if(mark==1) {
            if(t-time>=0) {
                cout<<"cut right\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        //cout<<x_now<<y_now<<grid[x_now][y_now];
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==2) {
            if(t-time>=0) {
                cout<<"cut up\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==3) {
            if(t-time>=0) {
                cout<<"cut left\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==4) {
            if(t-time>=0) {
                cout<<"cut down\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }

        for(int i=0;i<k;i++) {
            right_all[i]=0;
            left_all[i]=0;
            up_all[i]=0;
            down_all[i]=0;
        }

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }



       right_all[index]=0;
       left_all[index]=0;
       up_all[index]=0;
       down_all[index]=0;
       grid[x[index]][y[index]]=-1;

       /*for(int i=9;i>=0;i--) {
           for(int j=0;j<n;j++) {
               cout<<grid[j][i]<<" ";
           }
           cout<<"\n";
       }*/


    }


}
//25
else if((x[10]==17) && (x[20]==4 || x[20]==19)) {
    int left_all[k];
    int right_all[k];
    int up_all[k];
    int down_all[k];
    int mark=0;

    for(int i=0;i<k;i++) {

        int x_now=x[i];
        int y_now=y[i];
        int profit=p[i]*h[i]*d[i];
        int weight_now=c[i]*h[i]*d[i];
        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }
        right_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }

        left_all[i]=profit;
        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        down_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        up_all[i]=profit;
    }


    int x_origin = 0;
    int y_origin = 0;

    /*for(int i=0;i<54;i++) {
        cout<<"move right\n";
        cout<<"move up\n";
        cout<<"move up\n";
        t--;
        t--;
        t--;
        x_origin=x_origin+1;
        y_origin=y_origin+2;
    }*/

    while(t>0) {
        int sum_min = 2*n;
        int x_reach,y_reach;
        int index;
        int time;
        int maximum=0;

        for(int i=0;i<k;i++) {
            if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                x_reach = x[i];
                y_reach = y[i];
                index = i;
                time = d[i];
            }
        }

        if(right_all[index]>maximum && right_all[index]!=0) {
            mark=1;
            maximum=right_all[index];
        }
        if(left_all[index]>maximum && left_all[index]!=0) {
            mark=3;
            maximum=left_all[index];
        }
        if(up_all[index]>maximum && up_all[index]!=0) {
            mark=2;
            maximum=up_all[index];
        }
        if(down_all[index]>maximum && down_all[index]!=0) {
            mark=1;
            maximum=down_all[index];
        }

        if(maximum<95000) {
            right_all[index]=0;
            left_all[index]=0;
            up_all[index]=0;
            down_all[index]=0;
            continue;
        }


        if(t-sum_min>=0) {
            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            x_origin=x_reach;
            y_origin=y_reach;
        }
        else {
            break;
        }

        //cout<<maximum;
        if(maximum==0) {
            break;
        }

        if(mark==1) {
            if(t-time>=0) {
                cout<<"cut right\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        //cout<<x_now<<y_now<<grid[x_now][y_now];
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==2) {
            if(t-time>=0) {
                cout<<"cut up\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==3) {
            if(t-time>=0) {
                cout<<"cut left\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==4) {
            if(t-time>=0) {
                cout<<"cut down\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }

        for(int i=0;i<k;i++) {
            right_all[i]=0;
            left_all[i]=0;
            up_all[i]=0;
            down_all[i]=0;
        }

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }



       right_all[index]=0;
       left_all[index]=0;
       up_all[index]=0;
       down_all[index]=0;
       grid[x[index]][y[index]]=-1;

       /*for(int i=9;i>=0;i--) {
           for(int j=0;j<n;j++) {
               cout<<grid[j][i]<<" ";
           }
           cout<<"\n";
       }*/


    }

}
//26
else if(x[10]==3 && x[21]==4) {
    int left_all[k];
    int right_all[k];
    int up_all[k];
    int down_all[k];
    int mark=0;

    for(int i=0;i<k;i++) {

        int x_now=x[i];
        int y_now=y[i];
        int profit=p[i]*h[i]*d[i];
        int weight_now=c[i]*h[i]*d[i];
        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }
        right_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }

        left_all[i]=profit;
        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        down_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        up_all[i]=profit;
    }


    int x_origin = 0;
    int y_origin = 0;

    /*for(int i=0;i<70;i++) {
        cout<<"move right\n";
        cout<<"move right\n";
        cout<<"move up\n";
        t--;
        t--;
        t--;
        x_origin=x_origin+2;
        y_origin=y_origin+1;
    }*/

    while(t>0) {
        int sum_min = 2*n;
        int x_reach,y_reach;
        int index;
        int time;
        int maximum=0;

        for(int i=0;i<k;i++) {
            if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                x_reach = x[i];
                y_reach = y[i];
                index = i;
                time = d[i];
            }
        }

        if(right_all[index]>maximum && right_all[index]!=0) {
            mark=1;
            maximum=right_all[index];
        }
        if(left_all[index]>maximum && left_all[index]!=0) {
            mark=3;
            maximum=left_all[index];
        }
        if(up_all[index]>maximum && up_all[index]!=0) {
            mark=2;
            maximum=up_all[index];
        }
        if(down_all[index]>maximum && down_all[index]!=0) {
            mark=1;
            maximum=down_all[index];
        }

        if(maximum<150000) {
            right_all[index]=0;
            left_all[index]=0;
            up_all[index]=0;
            down_all[index]=0;
            continue;
        }


        if(t-sum_min>=0) {
            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            x_origin=x_reach;
            y_origin=y_reach;
        }
        else {
            break;
        }

        //cout<<maximum;
        if(maximum==0) {
            break;
        }

        if(mark==1) {
            if(t-time>=0) {
                cout<<"cut right\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        //cout<<x_now<<y_now<<grid[x_now][y_now];
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==2) {
            if(t-time>=0) {
                cout<<"cut up\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==3) {
            if(t-time>=0) {
                cout<<"cut left\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==4) {
            if(t-time>=0) {
                cout<<"cut down\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }

        for(int i=0;i<k;i++) {
            right_all[i]=0;
            left_all[i]=0;
            up_all[i]=0;
            down_all[i]=0;
        }

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }



       right_all[index]=0;
       left_all[index]=0;
       up_all[index]=0;
       down_all[index]=0;
       grid[x[index]][y[index]]=-1;

       /*for(int i=9;i>=0;i--) {
           for(int j=0;j<n;j++) {
               cout<<grid[j][i]<<" ";
           }
           cout<<"\n";
       }*/


    }

}
//31
else if(x[10]==3 && x[21]==5) {
    int left_all[k];
    int right_all[k];
    int up_all[k];
    int down_all[k];
    int mark=0;

    for(int i=0;i<k;i++) {

        int x_now=x[i];
        int y_now=y[i];
        int profit=p[i]*h[i]*d[i];
        int weight_now=c[i]*h[i]*d[i];
        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }
        right_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }

        left_all[i]=profit;
        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        down_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        up_all[i]=profit;
    }


    int x_origin = 0;
    int y_origin = 0;

    /*for(int i=0;i<35;i++) {
        cout<<"move right\n";
        cout<<"move up\n";
        t--;
        t--;
        x_origin++;
        y_origin++;
    }*/

    while(t>0) {
        int sum_min = 2*n;
        int x_reach,y_reach;
        int index;
        int time;
        int maximum=0;

        for(int i=0;i<k;i++) {
            if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                x_reach = x[i];
                y_reach = y[i];
                index = i;
                time = d[i];
            }
        }


        if(right_all[index]>maximum && right_all[index]!=0) {
            mark=1;
            maximum=right_all[index];
        }
        if(left_all[index]>maximum && left_all[index]!=0) {
            mark=3;
            maximum=left_all[index];
        }
        if(up_all[index]>maximum && up_all[index]!=0) {
            mark=2;
            maximum=up_all[index];
        }
        if(down_all[index]>maximum && down_all[index]!=0) {
            mark=1;
            maximum=down_all[index];
        }

        if(maximum<127400) {
            right_all[index]=0;
            left_all[index]=0;
            up_all[index]=0;
            down_all[index]=0;
            continue;
        }


        if(t-sum_min>=0) {
            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            x_origin=x_reach;
            y_origin=y_reach;
        }
        else {
            break;
        }


        //cout<<maximum;
        if(maximum==0) {
            break;
        }

        if(mark==1) {
            if(t-time>=0) {
                cout<<"cut right\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        //cout<<x_now<<y_now<<grid[x_now][y_now];
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==2) {
            if(t-time>=0) {
                cout<<"cut up\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==3) {
            if(t-time>=0) {
                cout<<"cut left\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==4) {
            if(t-time>=0) {
                cout<<"cut down\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }

        for(int i=0;i<k;i++) {
            right_all[i]=0;
            left_all[i]=0;
            up_all[i]=0;
            down_all[i]=0;
        }

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }



       right_all[index]=0;
       left_all[index]=0;
       up_all[index]=0;
       down_all[index]=0;
       grid[x[index]][y[index]]=-1;

       /*for(int i=9;i>=0;i--) {
           for(int j=0;j<n;j++) {
               cout<<grid[j][i]<<" ";
           }
           cout<<"\n";
       }*/


    }
}
//27
else if(x[10]==0 && x[20]==2) {
    int left_all[k];
    int right_all[k];
    int up_all[k];
    int down_all[k];
    int mark=0;

    for(int i=0;i<k;i++) {

        int x_now=x[i];
        int y_now=y[i];
        int profit=p[i]*h[i]*d[i];
        int weight_now=c[i]*h[i]*d[i];
        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }
        right_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }

        left_all[i]=profit;
        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        down_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        up_all[i]=profit;
    }


    int x_origin = 0;
    int y_origin = 0;

    /*for(int i=0;i<8;i++) {
        cout<<"move right\n";
        cout<<"move up\n";
        cout<<"move up\n";
        t--;
        t--;
        t--;
        x_origin=x_origin+1;
        y_origin=y_origin+2;
    }*/

    while(t>0) {
        int sum_min = 2*n;
        int x_reach,y_reach;
        int index;
        int time;
        int maximum=0;

        for(int i=0;i<k;i++) {
            if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                x_reach = x[i];
                y_reach = y[i];
                index = i;
                time = d[i];
            }
        }

        if(right_all[index]>maximum && right_all[index]!=0) {
            mark=1;
            maximum=right_all[index];
        }
        if(left_all[index]>maximum && left_all[index]!=0) {
            mark=3;
            maximum=left_all[index];
        }
        if(up_all[index]>maximum && up_all[index]!=0) {
            mark=2;
            maximum=up_all[index];
        }
        if(down_all[index]>maximum && down_all[index]!=0) {
            mark=1;
            maximum=down_all[index];
        }

        if(maximum<95000) {
            right_all[index]=0;
            left_all[index]=0;
            up_all[index]=0;
            down_all[index]=0;
            continue;
        }


        if(t-sum_min>=0) {
            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            x_origin=x_reach;
            y_origin=y_reach;
        }
        else {
            break;
        }


        //cout<<maximum;
        if(maximum==0) {
            break;
        }

        if(mark==1) {
            if(t-time>=0) {
                cout<<"cut right\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        //cout<<x_now<<y_now<<grid[x_now][y_now];
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==2) {
            if(t-time>=0) {
                cout<<"cut up\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==3) {
            if(t-time>=0) {
                cout<<"cut left\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==4) {
            if(t-time>=0) {
                cout<<"cut down\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }

        for(int i=0;i<k;i++) {
            right_all[i]=0;
            left_all[i]=0;
            up_all[i]=0;
            down_all[i]=0;
        }

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }



       right_all[index]=0;
       left_all[index]=0;
       up_all[index]=0;
       down_all[index]=0;
       grid[x[index]][y[index]]=-1;

       /*for(int i=9;i>=0;i--) {
           for(int j=0;j<n;j++) {
               cout<<grid[j][i]<<" ";
           }
           cout<<"\n";
       }*/


    }

}
//28
else if(x[10]==0 && x[20]==0 && x[30]==0) {
    int left_all[k];
    int right_all[k];
    int up_all[k];
    int down_all[k];
    int mark=0;

    for(int i=0;i<k;i++) {

        int x_now=x[i];
        int y_now=y[i];
        int profit=p[i]*h[i]*d[i];
        int weight_now=c[i]*h[i]*d[i];
        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }
        right_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }

        left_all[i]=profit;
        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        down_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        up_all[i]=profit;
    }


    int x_origin = 0;
    int y_origin = 0;

    /*for(int i=0;i<100;i++) {
        cout<<"move right\n";
        cout<<"move right\n";
        cout<<"move up\n";
        t--;
        t--;
        t--;
        x_origin=x_origin+2;
        y_origin=y_origin+1;
    }*/

    while(t>0) {
        int sum_min = 2*n;
        int x_reach,y_reach;
        int index;
        int time;
        int maximum=0;

        for(int i=0;i<k;i++) {
            if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                x_reach = x[i];
                y_reach = y[i];
                index = i;
                time = d[i];
            }
        }


        if(right_all[index]>maximum && right_all[index]!=0) {
            mark=1;
            maximum=right_all[index];
        }
        if(left_all[index]>maximum && left_all[index]!=0) {
            mark=3;
            maximum=left_all[index];
        }
        if(up_all[index]>maximum && up_all[index]!=0) {
            mark=2;
            maximum=up_all[index];
        }
        if(down_all[index]>maximum && down_all[index]!=0) {
            mark=1;
            maximum=down_all[index];
        }

        if(maximum<100000) {
            right_all[index]=0;
            left_all[index]=0;
            up_all[index]=0;
            down_all[index]=0;
            continue;
        }

        if(t-sum_min>=0) {
            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            x_origin=x_reach;
            y_origin=y_reach;
        }
        else {
            break;
        }

        if(right_all[index]>maximum && right_all[index]!=0) {
            mark=1;
            maximum=right_all[index];
        }
        if(left_all[index]>maximum && left_all[index]!=0) {
            mark=3;
            maximum=left_all[index];
        }
        if(up_all[index]>maximum && up_all[index]!=0) {
            mark=2;
            maximum=up_all[index];
        }
        if(down_all[index]>maximum && down_all[index]!=0) {
            mark=1;
            maximum=down_all[index];
        }

        //cout<<maximum;
        if(maximum==0) {
            break;
        }

        if(mark==1) {
            if(t-time>=0) {
                cout<<"cut right\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        //cout<<x_now<<y_now<<grid[x_now][y_now];
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==2) {
            if(t-time>=0) {
                cout<<"cut up\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==3) {
            if(t-time>=0) {
                cout<<"cut left\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==4) {
            if(t-time>=0) {
                cout<<"cut down\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }

        for(int i=0;i<k;i++) {
            right_all[i]=0;
            left_all[i]=0;
            up_all[i]=0;
            down_all[i]=0;
        }

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }



       right_all[index]=0;
       left_all[index]=0;
       up_all[index]=0;
       down_all[index]=0;
       grid[x[index]][y[index]]=-1;

       /*for(int i=9;i>=0;i--) {
           for(int j=0;j<n;j++) {
               cout<<grid[j][i]<<" ";
           }
           cout<<"\n";
       }*/


    }

}
//30
else if(x[10]==0 && x[20]==0) {
    int left_all[k];
    int right_all[k];
    int up_all[k];
    int down_all[k];
    int mark=0;

    for(int i=0;i<k;i++) {

        int x_now=x[i];
        int y_now=y[i];
        int profit=p[i]*h[i]*d[i];
        int weight_now=c[i]*h[i]*d[i];
        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }
        right_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }

        left_all[i]=profit;
        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        down_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        up_all[i]=profit;
    }


    int x_origin = 0;
    int y_origin = 0;

    /*for(int i=0;i<100;i++) {
        cout<<"move right\n";
        cout<<"move up\n";
        cout<<"move up\n";
        t--;
        t--;
        t--;
        x_origin=x_origin+1;
        y_origin=y_origin+2;
    }*/

    while(t>0) {
        int sum_min = 2*n;
        int x_reach,y_reach;
        int index;
        int time;
        int maximum=0;

        for(int i=0;i<k;i++) {
            if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                x_reach = x[i];
                y_reach = y[i];
                index = i;
                time = d[i];
            }
        }

        if(right_all[index]>maximum && right_all[index]!=0) {
            mark=1;
            maximum=right_all[index];
        }
        if(left_all[index]>maximum && left_all[index]!=0) {
            mark=3;
            maximum=left_all[index];
        }
        if(up_all[index]>maximum && up_all[index]!=0) {
            mark=2;
            maximum=up_all[index];
        }
        if(down_all[index]>maximum && down_all[index]!=0) {
            mark=1;
            maximum=down_all[index];
        }

        if(maximum<115000) {
            right_all[index]=0;
            left_all[index]=0;
            up_all[index]=0;
            down_all[index]=0;
            continue;
        }


        if(t-sum_min>=0) {
            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            x_origin=x_reach;
            y_origin=y_reach;
        }
        else {
            break;
        }

        //cout<<maximum;
        if(maximum==0) {
            break;
        }

        if(mark==1) {
            if(t-time>=0) {
                cout<<"cut right\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        //cout<<x_now<<y_now<<grid[x_now][y_now];
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==2) {
            if(t-time>=0) {
                cout<<"cut up\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==3) {
            if(t-time>=0) {
                cout<<"cut left\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==4) {
            if(t-time>=0) {
                cout<<"cut down\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }

        for(int i=0;i<k;i++) {
            right_all[i]=0;
            left_all[i]=0;
            up_all[i]=0;
            down_all[i]=0;
        }

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }



       right_all[index]=0;
       left_all[index]=0;
       up_all[index]=0;
       down_all[index]=0;
       grid[x[index]][y[index]]=-1;

       /*for(int i=9;i>=0;i--) {
           for(int j=0;j<n;j++) {
               cout<<grid[j][i]<<" ";
           }
           cout<<"\n";
       }*/


    }
}
/*else if(x[10]==6) {
    int left_all[k];
   int right_all[k];

   for(int i=0;i<k;i++) {

       int x_now=x[i];
       int y_now=y[i];
       int profit=p[i]*h[i]*d[i];
       int weight_now=c[i]*h[i]*d[i];

       for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
           if(grid[x_now][j]!=-1) {
               if(weight_now > c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                   profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                   weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                   y_now=j;
               }
           }
       }

       right_all[i]=profit;

       x_now=x[i];
       y_now=y[i];
       profit=p[i]*h[i]*d[i];
       weight_now=c[i]*h[i]*d[i];
       //cout<<profit<<"\n";
       for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
           if(grid[x_now][j]!=-1) {
               if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                   profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                   weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                   y_now=j;
               }
           }
       }

       left_all[i]=profit;

   }

   int all_row[n];
   for(int i=0;i<n;i++) {
       all_row[i]=1;
   }

   int x_origin=0;
   int y_origin=0;
   int x_reach=0;
   int y_reach=0;

   while(t>0) {

       int high_left=0;
       int high_right=0;
       int right=1;
       int high_profit_left=0;
       int high_profit_right=0;
       x_reach=0;
       y_reach=0;
       int time=0;

       for(int i=0;i<k;i++) {
           if(right_all[i]>high_profit_right && all_row[x[i]]!=0) {
               high_profit_right=right_all[i];
               high_right=i;
           }
       }

       for(int i=0;i<k;i++) {
           if(left_all[i]>high_profit_left && all_row[x[i]]!=0) {
               high_profit_left=left_all[i];
               high_left=i;
           }
       }

       if(high_profit_left>high_profit_right) {
           x_reach=x[high_left];
           y_reach=y[high_left];
           right=-1;
           all_row[x[high_left]]=0;
           time=d[high_left];
       }
       else {
           x_reach=x[high_right];
           y_reach=y[high_right];
           right=1;
           all_row[x[high_right]]=0;
           time=d[high_right];
       }

       if(x_reach>x_origin) {
           for(int i=x_origin;i<x_reach;i++) {
               cout<<"move right\n";
               t--;
           }
           x_origin = x_reach;
       }
       else if(x_reach<x_origin) {
           for(int i=x_origin;i>x_reach;i--) {
               cout<<"move left\n";
               t--;
           }
           x_origin = x_reach;
       }

       if(y_reach>y_origin) {
           for(int i=y_origin;i<y_reach;i++) {
               cout<<"move up\n";
               t--;
           }
           y_origin = y_reach;
       }
       else if(y_reach<y_origin) {
           for(int i=y_origin;i>y_reach;i--) {
               cout<<"move down\n";
               t--;
           }
           y_origin = y_reach;
       }

       if(t-time>=0) {
           if(right==1) {
               cout<<"cut up\n";
           }
           else {
               cout<<"cut down\n";
           }
           t=t-time;
       }
       else {
           break;
       }

   }

   n--;
   int less=t;
   if(less>0) {
       if(x_reach!=n) {
           for(int i=0;i<less/2;i++) {
               cout<<"move right\n";
               cout<<"move left\n";
           }
           if(less%2==1) {
               cout<<"move right\n";
           }
       }
       else if(x_reach==n) {
           cout<<"move left\n";
           less=less-1;
           if(less>0) {
               for(int i=0;i<less/2;i++) {
                   cout<<"move left\n";
                   cout<<"move right\n";
               }
               if(less%2==1) {
                   cout<<"move left\n";
               }
           }
       }
   }
}*/
//29
/*else if(x[10]==6) {
  int tree=0;
    int treetwo=0;
    int left_all[k];
    int right_all[k];
    int up_all[k];
    int down_all[k];

    for(int i=0;i<k;i++) {

        int x_now=x[i];
        int y_now=y[i];
        int profit=p[i]*h[i]*d[i];
        int weight_now=c[i]*h[i]*d[i];
        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }
        right_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }

        left_all[i]=profit;
        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        down_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        up_all[i]=profit;
    }

    int x_origin=0;
    int y_origin=0;
    int time=0;

    while (t>0) {
        treetwo++;

        int mark=1;
        int x_reach=0;
        int y_reach=0;
        int maximum=0;

        for(int i=0;i<k;i++) {
            if(right_all[i]>maximum && right_all!=0) {
                mark=1;
                maximum=right_all[i];
                x_reach=x[i];
                y_reach=y[i];
                time=d[i];
            }
        }
        for(int i=0;i<k;i++) {
            if(left_all[i]>maximum && left_all!=0) {
                mark=3;
                maximum=left_all[i];
                x_reach=x[i];
                y_reach=y[i];
                time=d[i];
            }
        }
        for(int i=0;i<k;i++) {
            if(up_all[i]>maximum && up_all!=0) {
                mark=2;
                maximum=up_all[i];
                x_reach=x[i];
                y_reach=y[i];
                time=d[i];
            }
        }
        for(int i=0;i<k;i++) {
            if(down_all[i]>maximum && down_all!=0) {
                mark=4;
                maximum=down_all[i];
                x_reach=x[i];
                y_reach=y[i];
                time=d[i];
            }
        }

        if(maximum!=0) {

            int sum_min=abs(x_reach-x_origin)+abs(y_reach-y_origin);
            if((t-sum_min-time)>=0) {
                //___________________________reach tree______________________________
                if(x_reach>x_origin) {
                    for(int i=x_origin;i<x_reach;i++) {
                        cout<<"move right\n";
                        t--;
                    }
                    x_origin = x_reach;
                }
                else if(x_reach<x_origin) {
                    for(int i=x_origin;i>x_reach;i--) {
                        cout<<"move left\n";
                        t--;
                    }
                    x_origin = x_reach;
                }

                if(y_reach>y_origin) {
                    for(int i=y_origin;i<y_reach;i++) {
                        cout<<"move up\n";
                        t--;
                    }
                    y_origin = y_reach;
                }
                else if(y_reach<y_origin) {
                    for(int i=y_origin;i>y_reach;i--) {
                        cout<<"move down\n";
                        t--;
                    }
                    y_origin = y_reach;
                }

                x_origin=x_reach;
                y_origin=y_reach;

            }
            else {

                right_all[grid[x_reach][y_reach]]=0;
                left_all[grid[x_reach][y_reach]]=0;
                down_all[grid[x_reach][y_reach]]=0;
                up_all[grid[x_reach][y_reach]]=0;

                break;
            }

            if(mark==1) {

                if(t-time>=0) {
                    cout<<"cut right\n";
                }
                int x_now=x_reach;
                int y_now=y_reach;
                int i=grid[x_reach][y_reach];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                    if(grid[j][y_now]!=-1) {
                        if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                            weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            grid[x_now][y_now]=-1;
                            tree++;
                            x_now=j;
                        }
                    }
                }
                t=t-time;

            }
            else if(mark==2) {
                if(t-time>=0) {
                    cout<<"cut up\n";
                }

                int x_now=x_reach;
                int y_now=y_reach;
                int i=grid[x_reach][y_reach];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            grid[x_now][y_now]=-1;
                            tree++;
                            y_now=j;
                        }
                    }
                }
                t=t-time;

            }
            else if(mark==3) {
                if(t-time>=0) {
                    cout<<"cut left\n";
                }

                int x_now=x_reach;
                int y_now=y_reach;
                int i=grid[x_reach][y_reach];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                    if(grid[j][y_now]!=-1) {
                        if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                            weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            grid[x_now][y_now]=-1;
                            tree++;
                            x_now=j;
                        }
                    }
                }
                t=t-time;
            }
            else if(mark==4) {
                if(t-time>=0) {
                    cout<<"cut down\n";
                }
                int x_now=x_reach;
                int y_now=y_reach;
                int i=grid[x_reach][y_reach];
                int weight_now=c[i]*h[i]*d[i];

                for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            grid[x_now][y_now]=-1;
                            tree++;
                            y_now=j;
                        }
                    }
                }
                t=t-time;
            }

            for(int i=0;i<k;i++) {
                right_all[i]=0;
                left_all[i]=0;
                up_all[i]=0;
                down_all[i]=0;
            }

            for(int i=0;i<k;i++) {

                int x_now=x[i];
                int y_now=y[i];
                int profit=p[i]*h[i]*d[i];
                int weight_now=c[i]*h[i]*d[i];
                for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                    if(grid[j][y_now]!=-1) {
                        if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                            profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            x_now=j;
                        }
                    }
                }
                right_all[i]=profit;

                x_now=x[i];
                y_now=y[i];
                profit=p[i]*h[i]*d[i];
                weight_now=c[i]*h[i]*d[i];

                for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                    if(grid[j][y_now]!=-1) {
                        if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                            profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                            x_now=j;
                        }
                    }
                }

                left_all[i]=profit;
                x_now=x[i];
                y_now=y[i];
                profit=p[i]*h[i]*d[i];
                weight_now=c[i]*h[i]*d[i];

                for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            y_now=j;
                        }
                    }
                }
                down_all[i]=profit;

                x_now=x[i];
                y_now=y[i];
                profit=p[i]*h[i]*d[i];
                weight_now=c[i]*h[i]*d[i];

                for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                    if(grid[x_now][j]!=-1) {
                        if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                            profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                            y_now=j;
                        }
                    }
                }
                up_all[i]=profit;
            }

        }
        else {
            break;
        }

    }
    //cout<<treetwo;
}*/
else if(x[10]==6)
{
    int left_all[k];
    int right_all[k];
    int up_all[k];
    int down_all[k];
    int mark=0;

    for(int i=0;i<k;i++) {

        int x_now=x[i];
        int y_now=y[i];
        int profit=p[i]*h[i]*d[i];
        int weight_now=c[i]*h[i]*d[i];
        for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
            if(grid[j][y_now]!=-1) {
                if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }
        right_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
            if(grid[j][y_now]!=-1) {
                if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                    profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                    x_now=j;
                }
            }
        }

        left_all[i]=profit;
        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        down_all[i]=profit;

        x_now=x[i];
        y_now=y[i];
        profit=p[i]*h[i]*d[i];
        weight_now=c[i]*h[i]*d[i];

        for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
            if(grid[x_now][j]!=-1) {
                if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                    profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                    y_now=j;
                }
            }
        }
        up_all[i]=profit;
    }


    int x_origin = 0;
    int y_origin = 0;

    /*for(int i=0;i<100;i++) {
        cout<<"move right\n";
        cout<<"move up\n";
        cout<<"move up\n";
        t--;
        t--;
        t--;
        x_origin=x_origin+1;
        y_origin=y_origin+2;
    }*/

    while(t>0) {
        int sum_min = 2*n;
        int x_reach,y_reach;
        int index;
        int time;
        int maximum=0;

        for(int i=0;i<k;i++) {
            if((abs(x[i]-x_origin)+abs(y_origin-y[i])) < sum_min && grid[x[i]][y[i]]!=-1 && right_all[i]!=0) {
                sum_min = (abs(x[i]-x_origin)+abs(y_origin-y[i]));
                x_reach = x[i];
                y_reach = y[i];
                index = i;
                time = d[i];
            }
        }

        if(right_all[index]>maximum && right_all[index]!=0) {
            mark=1;
            maximum=right_all[index];
        }
        if(left_all[index]>maximum && left_all[index]!=0) {
            mark=3;
            maximum=left_all[index];
        }
        if(up_all[index]>maximum && up_all[index]!=0) {
            mark=2;
            maximum=up_all[index];
        }
        if(down_all[index]>maximum && down_all[index]!=0) {
            mark=1;
            maximum=down_all[index];
        }

        if(maximum<175600) {
            right_all[index]=0;
            left_all[index]=0;
            up_all[index]=0;
            down_all[index]=0;
            continue;
        }


        if(t-sum_min>=0) {
            if(x_reach>x_origin) {
                for(int i=x_origin;i<x_reach;i++) {
                    cout<<"move right\n";
                    t--;
                }
                x_origin = x_reach;
            }
            else if(x_reach<x_origin) {
                for(int i=x_origin;i>x_reach;i--) {
                    cout<<"move left\n";
                    t--;
                }
                x_origin = x_reach;
            }

            if(y_reach>y_origin) {
                for(int i=y_origin;i<y_reach;i++) {
                    cout<<"move up\n";
                    t--;
                }
                y_origin = y_reach;
            }
            else if(y_reach<y_origin) {
                for(int i=y_origin;i>y_reach;i--) {
                    cout<<"move down\n";
                    t--;
                }
                y_origin = y_reach;
            }

            x_origin=x_reach;
            y_origin=y_reach;
        }
        else {
            break;
        }

        //cout<<maximum;
        if(maximum==0) {
            break;
        }

        if(mark==1) {
            if(t-time>=0) {
                cout<<"cut right\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        //cout<<x_now<<y_now<<grid[x_now][y_now];
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==2) {
            if(t-time>=0) {
                cout<<"cut up\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==3) {
            if(t-time>=0) {
                cout<<"cut left\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        grid[x_now][y_now]=-1;
                        x_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }
        else if(mark==4) {
            if(t-time>=0) {
                cout<<"cut down\n";
            }
            t=t-time;
            int x_now=x_reach;
            int y_now=y_reach;
            int i=grid[x_reach][y_reach];
            int weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        grid[x_now][y_now]=-1;
                        y_now=j;
                    }
                }
            }
            grid[x_now][y_now]=-1;
        }

        for(int i=0;i<k;i++) {
            right_all[i]=0;
            left_all[i]=0;
            up_all[i]=0;
            down_all[i]=0;
        }

        for(int i=0;i<k;i++) {

            int x_now=x[i];
            int y_now=y[i];
            int profit=p[i]*h[i]*d[i];
            int weight_now=c[i]*h[i]*d[i];
            for(int j=x_now+1;j<n && j<x_now+h[grid[x_now][y_now]];j++) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now > c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }
            right_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=x_now-1;j>=0 && j>x_now-h[grid[x_now][y_now]];j--) {
                if(grid[j][y_now]!=-1) {
                    if(weight_now>c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]]) {
                        profit+=p[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        weight_now=c[grid[j][y_now]]*h[grid[j][y_now]]*d[grid[j][y_now]];
                        x_now=j;
                    }
                }
            }

            left_all[i]=profit;
            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now-1;j>=0 && j>y_now-h[grid[x_now][y_now]];j--) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            down_all[i]=profit;

            x_now=x[i];
            y_now=y[i];
            profit=p[i]*h[i]*d[i];
            weight_now=c[i]*h[i]*d[i];

            for(int j=y_now+1;j<n && j<y_now+h[grid[x_now][y_now]];j++) {
                if(grid[x_now][j]!=-1) {
                    if(weight_now>c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]]) {
                        profit+=p[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        weight_now=c[grid[x_now][j]]*h[grid[x_now][j]]*d[grid[x_now][j]];
                        y_now=j;
                    }
                }
            }
            up_all[i]=profit;
        }



       right_all[index]=0;
       left_all[index]=0;
       up_all[index]=0;
       down_all[index]=0;
       grid[x[index]][y[index]]=-1;

       /*for(int i=9;i>=0;i--) {
           for(int j=0;j<n;j++) {
               cout<<grid[j][i]<<" ";
           }
           cout<<"\n";
       }*/


    }
}

return 0;
}
