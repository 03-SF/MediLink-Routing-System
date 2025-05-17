#include<iostream>

using namespace std;


#define sa  15


string DWatson[sa] = {"F-6", "BlueArea", "PWD", "ChandniChowk", "MallRoadSaddar", "I-9", "RedZone", "G-13", "Westridge",
                      "BahriaTown", "SatteliteTown", "MurreeRoad", "Aabpara", "ShahzadTown", "GulbergGreen"
};

string Shaheen[sa] = {"MallRoadSaddar", "F-6", "BlueArea", "ChacklalaScheme3", "BahriaPhase4", "G-7",
                      "DHAPhase1", "Rehamanabad", "Morgah", "F-10",
                      "BharaKahu", "H-8", "CommercialMarket", "E-11", "I-14"};

double dw[sa][sa];
double sh[sa][sa];
double Graph[sa][sa];
double dst[sa];
string parent[sa];

bool visitd[sa];

void Prims(int, double[sa][sa]);

void insertdwatson(int, int, double);

void insertshaheen(int, int, double);

void mstadd(int, int, double);

int locpos(string, int, string[]);


void print(int[sa][sa]);

double distancecaluation(int, int, int, string[sa]);


void Parents(int, int, string[]);


int main() {
    bool rerun;
    rerun = true;
    while (rerun) {
        cout
                << "*********************************************************************************************************"
                << endl;

        cout << "Medicine Delivery Routing System using PRIMS Algorithm" << endl;

        cout
                << "*********************************************************************************************************"
                << endl;

        int mainmenuopt;
        cout << "Dashboard " << endl;
        cout << "Select Pharmacy" << endl;
        cout << "DWatson Pharmacy (Enter 0)" << endl;
        cout << "Shaheen Pharmacy (Enter 1)" << endl;

        cin >> mainmenuopt;

        if (mainmenuopt == 0) {
            cout << "********************" << endl;
            cout << "DWATSON" << endl;
            cout << "********************" << endl;

            // F-6
            insertdwatson(0, 5, 11.8);
            insertdwatson(0, 6, 3.6);
            insertdwatson(0, 12, 4.2);

            //Blue Area
            insertdwatson(1, 5, 11.5);
            insertdwatson(1, 6, 3.7);
            insertdwatson(1, 12, 3.3);
            insertdwatson(1, 13, 13.4);

            //ChadniChowk
            insertdwatson(3, 11, 2.8);
            insertdwatson(3, 8, 7.4);
            insertdwatson(3, 10, 1.7);

            //Mall road Saddar
            insertdwatson(4, 8, 4.8);
            insertdwatson(4, 11, 4.4);
            insertdwatson(4, 10, 6.9);
            insertdwatson(4, 9, 11.2);



            // I-9


            insertdwatson(5, 7, 13.5);
            insertdwatson(5, 12, 8.7);
            insertdwatson(5, 13, 11.4);

            //Westridge
            insertdwatson(8, 10, 9.0);
            insertdwatson(8, 11, 11.0);


            // Red Zone

            insertdwatson(6, 12, 6.0);
            insertdwatson(6, 5, 13.8);


            //MurreeRoad
            insertdwatson(11, 8, 11.0);
            insertdwatson(11, 10, 3.5);

            // Sattelite Town

            insertdwatson(10, 11, 3.5);
            insertdwatson(10, 8, 6.7);
            insertdwatson(10, 12, 11.6);
            insertdwatson(10, 5, 3.8);

            //PWD
            insertdwatson(2, 6, 11);
            insertdwatson(2, 7, 11.4);
            insertdwatson(2, 5, 5.8);

            //Gulberg
            insertdwatson(14, 9, 12.1);
            insertdwatson(14, 11, 13.8);


            for (int i = 0; i < sa; ++i) {
                for (int j = 0; j < sa; ++j) {
                    Graph[i][j] = 0;

                }

            }



            Prims(sa, dw);


            cout << "Available Deliverable Locations " << endl;
            for (int i = 5; i < sa; ++i) {

                cout << DWatson[i] << "    ";
                if (i % 5 == 0 && i != 5) {
                    cout << endl;
                }

            }
            cout << endl;

            string custloc;
            cout << "Enter Your Location" << endl;
            cin >> custloc;

            for (int i = 0; i < sa; ++i) {
                dst[i] = -1;
            }

            int a = locpos(custloc, sa, DWatson);

            Parents(a, sa, DWatson);


            if (a != -1) {
                char recon = 'Y';
                while (recon == 'Y') {
                    cout << "Available Branches " << endl;
                    for (int i = 0; i < 5; ++i) {
                        cout << DWatson[i] << endl;

                    }
                    string branch;
                    cout << "From Which Branch you want to Order" << endl;
                    cin >> branch;
                    bool ext = false;


                    for (int i = 0; i < sa; ++i) {
                        if (DWatson[i] == branch) {
                            ext = true;
                        }


                    }


                    if (ext) {

                        int b = locpos(branch, sa, DWatson);

                        double distance = distancecaluation(a, b, sa, DWatson);

                        if (b != -1) {



                            if (distance < 16) {
                                cout << "Distance =" << distance << endl;
                                cout << endl;
                                recon = 'N';
                            } else {
                                cout << "\n\nDelievery not possible in this region from this Branch (Ditance= )"
                                     << distance << "\n\n ";
                            }


                        } else {
                            cout << "This Place is not included in the delievery Route.";
                        }
                    } else {
                        cout << "Not Such Branch Found\n";
                        cout << "Continue? ";
                        cin >> recon;
                    }


                }
            }


        } else if (mainmenuopt == 1) {
// Shaheen Chemist
            cout << "********************" << endl;
            cout << "Shaheen Chemist" << endl;
            cout << "********************" << endl;

            // Bharia Branch
            insertshaheen(4, 6, 8.6);
            insertshaheen(4, 8, 7.9);


            //F-6
            insertshaheen(1, 5, 4.1);
            insertshaheen(1, 9, 9.6);
            insertshaheen(1, 11, 7.3);
            insertshaheen(1, 13, 11.6);

            //ChacklalaScheme3
            insertshaheen(3, 7, 8.3);
            insertshaheen(3, 14, 14);
            insertshaheen(3, 6, 12);
            insertshaheen(3, 12, 8.2);
            insertshaheen(3, 8, 5.4);

            //Blue Area
            insertshaheen(2, 9, 9.1);
            insertshaheen(2, 11, 7.1);
            insertshaheen(2, 13, 11.5);
            insertshaheen(2, 10, 13.7);

            //mall Road saddar
            insertshaheen(0, 6, 8.8);
            insertshaheen(0, 7, 6.1);
            insertshaheen(0, 8, 6.0);
            insertshaheen(0, 12, 6.1);
            insertshaheen(0, 13, 16);
            insertshaheen(0, 14, 10);

            // G-7
            insertshaheen(5, 9, 7.7);
            insertshaheen(5, 11, 2.9);
            insertshaheen(5, 13, 11.8);
            insertshaheen(5, 12, 11);
            insertshaheen(5, 10, 13.1);


            // DHAPHASE1

            insertshaheen(6, 10, 4.0);
            insertshaheen(6, 12, 13.1);

            //F10
            insertshaheen(9, 11, 7.9);
            insertshaheen(9, 13, 4.1);
            insertshaheen(9, 5, 7.7);

            //barakahu
            insertshaheen(10, 5, 3.0);
            insertshaheen(10, 11, 4.2);
            insertshaheen(10, 12, 11);
            insertshaheen(10, 13, 13);

            //Commercial Market
            insertshaheen(12, 7, 1.4);
            insertshaheen(12, 5, 10);
            insertshaheen(12, 6, 13);
            insertshaheen(12, 8, 11);
            insertshaheen(12, 14, 13);
            insertshaheen(12, 10, 11);

            //Rehmanabad
            insertshaheen(7, 12, 1.5);
            insertshaheen(7, 5, 11);
            insertshaheen(7, 6, 3);



            // Morgah
            insertshaheen(8, 12, 12.2);
            insertshaheen(8, 7, 12.3);
            insertshaheen(8, 6, 4);



            //E11
            insertshaheen(13, 11, 12.1);
            insertshaheen(13, 9, 4.2);
            insertshaheen(13, 5, 11.8);

            //I-14
            insertshaheen(14, 9, 14.0);
            insertshaheen(14, 12, 13.0);

            //H8
            insertshaheen(11, 5, 4.1);

            insertshaheen(11, 7, 9.6);
            insertshaheen(11, 9, 9.6);
            insertshaheen(11, 10, 4.2);
            insertshaheen(11, 12, 9.0);
            insertshaheen(11, 13, 13);


            for (int i = 0; i < sa; ++i) {
                for (int j = 0; j < sa; ++j) {
                    Graph[i][j] = 0;

                }

            }


            
            Prims(sa, sh);


            cout << "Available Deliverable Locations " << endl;
            for (int i = 5; i < sa; ++i) {

                cout << Shaheen[i] << "    ";
                if (i % 5 == 0 && i != 5) {
                    cout << endl;
                }

            }
            cout << endl;

            string custloc;
            cout << "Enter Your Location" << endl;
            cin >> custloc;

            for (int i = 0; i < sa; ++i) {
                dst[i] = -1;
            }

            int a = locpos(custloc, sa, Shaheen);

            Parents(a, sa, Shaheen);


            if (a != -1) {
                char recon = 'Y';
                while (recon == 'Y') {
                    cout << "Available Branches " << endl;
                    for (int i = 0; i < 5; ++i) {
                        cout << Shaheen[i] << endl;

                    }
                    string branch;
                    cout << "From Which Branch you want to Order" << endl;
                    cin >> branch;
                    bool ext = false;


                    for (int i = 0; i < sa; ++i) {
                        if (Shaheen[i] == branch) {
                            ext = true;
                        }


                    }


                    if (ext) {

                        int b = locpos(branch, sa, Shaheen);


                        double distance = distancecaluation(a, b, sa, Shaheen);

                        if (b != -1 && distance != 0.0) {

                            cout << "Distance =" << distance << endl;

                            if (distance < 30) {

                                cout << endl;
                                recon = 'N';
                            } else {
                                cout << "\n\nDelievery not possible in this region from this Branch (Ditance= )"
                                     << distance << "\n\n ";
                            }


                        } else {
                            cout << "This Place is not included in the delievery Route.";
                        }
                    } else {
                        cout << "Not Such Branch Found\n";
                        cout << "Continue? ";
                        cin >> recon;
                    }


                }
            }


        }


        cout << "Do you want to Continue" << endl;
        cin >> rerun;
    }


}


void insertdwatson(int va, int vb, double distancebtwpnts) {
    dw[va][vb] = distancebtwpnts;
    dw[vb][va] = distancebtwpnts;
}

void insertshaheen(int va, int vb, double distancebtwpnts) {
    sh[va][vb] = distancebtwpnts;
    sh[vb][va] = distancebtwpnts;

}

void mstadd(int x, int y, double distance) {

    Graph[x][y] = distance;
    Graph[y][x] = distance;
}

int locpos(string loc, int x, string alllocations[]) {
    int loccount = 0, i;

    for (i = 0; i < x; ++i) {
        if (loc == alllocations[i]) {
            loccount++;
            break;
        }

    }
    if (loccount == 0) {
        return -1;
    } else {
        return i;
    }

}

void print(int a[sa][sa]) {
    for (int i = 0; i < sa; ++i) {
        for (int j = 0; j < sa; ++j) {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
}


double distancecaluation(int a, int b, int v, string ar[sa]) {
    double total = 0.0;
    bool possible = true;
    if (parent[b] != ar[a]) {

        while (parent[b] != ar[a]) {
            if (total < 0) {
                possible = false;
                cout << endl << "Route Not Possible" << endl;
                break;
            }
            total += dst[b];

            cout << "------>" << ar[b] << "------>";

            b = locpos(parent[b], v, ar);


        }
        cout << "------>" << ar[b] << "------>";
        total += dst[b];

        cout << "------>" << ar[a] << endl;


    } else {

        total += dst[b];
    }
    if (possible) {
        return total;
    } else {
        return 0.0;
    }


}


void Parents(int a, int v, string ar[sa]) {
    for (int i = 0; i < v; ++i) {
        visitd[a] = true;
        for (int j = 0; j < v; ++j) {
            if (Graph[a][j] != 0 && (!visitd[j])) {

                dst[j] = Graph[a][j];

                parent[j] = ar[a];


            }

        }


        for (int k = 0; k < v; ++k) {
            if (dst[k] != -1 && (!visitd[k])) {
                a = k;

            }


        }

    }

}

void Prims(int vertix, double gp[sa][sa]) {
    bool visit[vertix];
    for (int i = 1; i < vertix; ++i) {
        visit[i] = false;
    }
    visit[0] = true;
    int edgecreated = 0;
    int min, x, y;
    while (edgecreated < vertix - 1) {
        min = INT_MAX;
        x = 0;
        y = 0;

        for (int i = 0; i < vertix; ++i) {
            if (visit[i] == true) {
                for (int j = 0; j < vertix; ++j) {
                    if (min > gp[i][j]) {
                        if (visit[j] == false && gp[i][j] != 0) {

                            min = gp[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }

        }

        visit[y] = true;
        edgecreated++;
        mstadd(x, y, gp[x][y]);


    }

}

