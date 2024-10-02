#include <string>  
#include <vector>  
  
using namespace std;  
  
string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {  
    string answer = "00:00";  
  
    int len_s = (int(video_len[0] - '0') * 10 + int(video_len[1] - '0')) * 60 + int(video_len[3] - '0') * 10 + int(video_len[4] - '0');  
    int pos_s = (int(pos[0] - '0') * 10 + int(pos[1] - '0')) * 60 + int(pos[3] - '0') * 10 + int(pos[4] - '0');  
    int start_s = (int(op_start[0] - '0') * 10 + int(op_start[1] - '0')) * 60 + int(op_start[3] - '0') * 10 + int(op_start[4] - '0');  
    int end_s = (int(op_end[0] - '0') * 10 + int(op_end[1] - '0')) * 60 + int(op_end[3] - '0') * 10 + int(op_end[4] - '0');  
  
    for (auto c : commands) {  
        if (c == "next") {  
            if (pos_s >= start_s && pos_s <= end_s) {  
                pos_s = end_s;  
            }
            if (pos_s > len_s - 10) {  
                pos_s = len_s;  
            } else {  
                pos_s += 10;  
            }  
            if (pos_s >= start_s && pos_s <= end_s) {  
                pos_s = end_s;  
            }
        }  
        if (c == "prev") {  
            if (pos_s < 10) {  
                pos_s = 0;  
            } else {  
                pos_s -= 10;  
            }  
        }  
    }  
  
    int minutes = pos_s / 60;  
    int seconds = pos_s % 60;  
  
    answer[0] = '0' + (minutes / 10);  
    answer[1] = '0' + (minutes % 10);  
    answer[3] = '0' + (seconds / 10);  
    answer[4] = '0' + (seconds % 10);  
  
    return answer;  
}  