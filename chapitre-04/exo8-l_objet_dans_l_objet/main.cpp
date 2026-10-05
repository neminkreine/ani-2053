#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct ObjectInfo {
    string name;
    string parent_name;
    long long tx, ty;
    long long angle;
    long long scale;

    long long wx, wy;
    long long w_angle;
    long long w_scale;
    long long level;
};


long long normalize_angle(long long a) {
    long long norm = a % 360;
    if (norm < 0) {
        norm += 360;
    }
    return norm;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N = 0;
    if (!(cin >> N)) return 0;

    unordered_map<string, ObjectInfo> objects_map;
    vector<ObjectInfo> objects_order;
    long long max_depth = 0;

    for (long long i = 0; i < N; ++i) {
        string name, parent;
        long long tx, ty, angle, scale;
        if (!(cin >> name >> parent >> tx >> ty >> angle >> scale)) break;

        ObjectInfo obj;
        obj.name = name;
        obj.parent_name = parent;
        obj.tx = tx;
        obj.ty = ty;
        obj.angle = angle;
        obj.scale = scale;

        if (parent == "-") {
            obj.wx = tx;
            obj.wy = ty;
            obj.w_angle = normalize_angle(angle);
            obj.w_scale = scale;
            obj.level = 1;
        } else {
            
            const ObjectInfo& p = objects_map[parent];

            
            long long ax = tx * p.w_scale;
            long long ay = ty * p.w_scale;

           
            long long c = 0, s = 0;
            long long p_norm_angle = p.w_angle;
            if (p_norm_angle == 0) {
                c = 1; s = 0;
            } else if (p_norm_angle == 90) {
                c = 0; s = 1;
            } else if (p_norm_angle == 180) {
                c = -1; s = 0;
            } else if (p_norm_angle == 270) {
                c = 0; s = -1;
            }

     
            long long rx = ax * c - ay * s;
            long long ry = ax * s + ay * c;

            
            obj.wx = p.wx + rx;
            obj.wy = p.wy + ry;

           
            obj.w_angle = normalize_angle(p.w_angle + angle);

           
            obj.w_scale = p.w_scale * scale;

            
            obj.level = p.level + 1;
        }

        max_depth = max(max_depth, obj.level);
        objects_map[name] = obj;
        objects_order.push_back(obj);
    }

    
    for (const auto& obj : objects_order) {
        cout << obj.name << " " << obj.wx << " " << obj.wy << " " << obj.w_angle << " " << obj.w_scale << "\n";
    }

    
    cout << "PROFONDEUR " << max_depth << "\n";

    return 0;
}