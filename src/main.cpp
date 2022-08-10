#include <bits/stdc++.h>

#include "../libraries/glm/glm.hpp"
#include "bvh.h"
#include "camera.h"
#include "config.h"
#include "ray.h"
#include "scene.h"
#include "triangle.h"
#include "utils.h"

using namespace std;

int main() {
    cout << "starting now" << endl;

    config conf;

    sphere sp1(glm::vec3(2, -2, -3), 1, "mirror");
    sphere sp2(glm::vec3(-0.1, 0.1, -0.8), 0.2, "glass");

    // light
    triangle tr1(
        vector<glm::vec3>{
            glm::vec3(-2.9, 2, -3.5),
            glm::vec3(-2.9, 2, 0.5),
            glm::vec3(-2.9, -2, 0.5),
        },
        "light");

    triangle tr2(
        vector<glm::vec3>{
            glm::vec3(-2.9, 2, -3.5),
            glm::vec3(-2.9, -2, 0.5),
            glm::vec3(-2.9, -2, -3.5),
        },
        "light");

    // pyramid
    triangle pyr1(
        vector<glm::vec3>{
            glm::vec3(0, 0.5, -1),
            glm::vec3(0.3, 0, -1.2),
            glm::vec3(0.6, 0.5, -0.8),
        },
        "mirror");

    triangle pyr2(
        vector<glm::vec3>{
            glm::vec3(0, 0.5, -1),
            glm::vec3(0.6, 0.5, -0.8),
            glm::vec3(0.3, 1, -1.2),
        },
        "mirror");

    triangle pyr3(
        vector<glm::vec3>{
            glm::vec3(0.6, 0.5, -0.8),
            glm::vec3(0.3, 0, -1.2),
            glm::vec3(0.3, 1, -1.2),
        },
        "mirror");

    triangle pyr4(
        vector<glm::vec3>{
            glm::vec3(0, 0.5, -1),
            glm::vec3(0.3, 1, -1.2),
            glm::vec3(0.3, 0, -1.2),
        },
        "mirror");

    plane p1(glm::vec3(-1, 0, 0), 3, "checker", conf.cornell_gray);
    plane p2(glm::vec3(1, 0, 0), 3, "diffuse", conf.cornell_gray);
    plane p3(glm::vec3(0, 1, 0), 3, "diffuse", conf.green);
    plane p4(glm::vec3(0, -1, 0), 3, "diffuse", conf.red);
    plane p5(glm::vec3(0, 0, 1), 4, "diffuse", conf.cornell_gray);
    plane p6(glm::vec3(0, 0, -1), 0.5, "diffuse", conf.cornell_gray);

    vector<triangle> vtr = makeCube(glm::vec3(0.5, 0.5, -1.5),
                                    glm::vec3(1, 1, -1), "diffuse", conf.blue);

    vector<triangle> vtr1 = vector<triangle>{tr1, tr2, pyr1, pyr2, pyr3, pyr4};
    vtr1.insert(vtr1.end(), vtr.begin(), vtr.end());

    bvh bvh1;
    bvh1.root = new bvhNode;
    bvh1.root->planes.push_back(&p1);
    bvh1.root->planes.push_back(&p2);
    bvh1.root->planes.push_back(&p3);
    bvh1.root->planes.push_back(&p4);
    bvh1.root->planes.push_back(&p5);
    bvh1.root->triangles.push_back(&tr1);
    bvh1.root->triangles.push_back(&tr2);
    bvh1.root->mn = glm::vec3(-5, -5, -5);
    bvh1.root->mx = glm::vec3(5, 5, 0.5);

    bvh1.root->l = new bvhNode;
    bvh1.root->l->spheres.push_back(&sp1);
    bvh1.root->l->leaf = true;
    bvh1.root->l->makeBB();

    bvh1.root->r = new bvhNode;
    bvhNode *rNode = bvh1.root->r;
    rNode->spheres.push_back(&sp2);
    rNode->triangles.push_back(&pyr1);
    rNode->triangles.push_back(&pyr2);
    rNode->triangles.push_back(&pyr3);
    rNode->triangles.push_back(&pyr4);
    rNode->makeBB();

    rNode->l = new bvhNode;
    bvhNode *rlNode = rNode->l;
    for (int i =0; i<vtr.size(); i++) {
        rlNode->triangles.push_back(&(vtr[i]));
    }
    rlNode->makeBB();
    // rlNode->mn = glm::vec3(0.5, 0.5, -1.5);
    // rlNode->mx = glm::vec3(1, 1, -1);
    rNode->unionBB(*rlNode);

    scene scn(vector<sphere>{sp1, sp2}, vector<plane>{p1, p2, p3, p4, p5}, vtr1,
              bvh1);
    bvh1.traverse();
    camera cam(conf, scn);

    cam.render();
    cam.write_img("output11.ppm");
}