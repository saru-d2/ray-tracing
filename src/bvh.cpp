#include "bvh.h"
using namespace std;


glm::vec3 Min(glm::vec3 a, glm::vec3 b) {
    return glm::vec3(min(a.x, b.x), min(a.y, b.y), min(a.z, b.z));
}

glm::vec3 Max(glm::vec3 a, glm::vec3 b) {
    return glm::vec3(max(a.x, b.x), max(a.y, b.y), max(a.z, b.z));
}

void bvh::traverse() {
    bvhNode *node = root;

    queue<pair<bvhNode *, int>> q;

    q.push({node, 0});

    while (!q.empty()) {
        auto fr = q.front();
        q.pop();

        cout << "NODE DEPTH: " << fr.second << " : planes"
             << fr.first->planes.size() << ", triangles"
             << fr.first->triangles.size() << ", spheres"
             << fr.first->spheres.size() << endl;
        glm::vec3 mn, mx;
        mn = fr.first->mn;
        mx = fr.first->mx;

        cout << mn.x << "," << mn.y << "," << mn.z << endl;
        cout << mx.x << "," << mx.y << "," << mx.z << endl << endl;

        if (fr.first->l) q.push({fr.first->l, fr.second + 1});
        if (fr.first->r) q.push({fr.first->r, fr.second + 1});
    }
}

void bvhNode::makeBB() {
    for (auto i : spheres) {
        mn = Min(mn, i->center - i->radius);
        mx = Max(mx, i->center + i->radius);
    }
    for (auto i : triangles) {
        for (auto j : i->verts) {
            mn = Min(mn, j);
            mx = Max(mx, j);
        }
    }
}