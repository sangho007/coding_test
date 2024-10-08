ector<int> v;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){    
            if(board[i][j] == 1 || vis[i][j] == 1) continue;
            vis[i][j] = 1;
            q.push({i,j});

            int area = 0;
            
            while(!q.empty()){
                auto cur = q.front();q.pop();
                area++;
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] == 1 || board[nx][ny] == 1) continue;
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }

            }
            if( area != 0) v.push_back(area);

        }
    }

    sort(v.begin(),v.end());
    cout << v.size() << '\n';
    for(auto n:v