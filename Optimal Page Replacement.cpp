#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int n;
int frame_size;
int pages[N];

void optimal_page_replacement(void)
{
    vector<int>frames;
    int j,k,page_faults,index,optimal;

    page_faults = 0;
    for(int i=0; i<n; i++)
    {
        for(k=0; k<frames.size(); k++)
        {
            if(frames[k] == pages[i]) break;
        }

        if(k == frames.size())
        {
            if(frames.size() == frame_size)
            {
                index = -1;
                optimal = 0;

                for(k=0; k<frames.size(); k++)
                {
                    for(j=i+1; j<n; j++)
                    {
                        if(pages[j] == frames[k])
                        {
                            if(j > index)
                            {
                                index = j;
                                optimal = k;
                            }
                            break;
                        }
                    }
                    if(j == n)
                    {
                        optimal = k;
                        index = n + 1;
                        break;
                    }
                }

                frames[optimal] = pages[i];
            }
            else
            {
                frames.push_back(pages[i]);
            }

            page_faults++;
            cout<<"Reference to page "<<pages[i]<<" caused a page fault\n";
        }
        else
        {
            cout<<"Reference to page "<<pages[i]<<" did not cause a page fault\n";
        }
    }
    cout<<"\nTotal Page Faults: "<<page_faults;
    return;
}

int main()
{
    cout<<"Number of Frames: ";
    cin>>frame_size;

    cout<<"Page Reference Stream Length: ";
    cin>>n;

    cout<<"Page Reference Stream:\n";
    for(int i=0; i<n; i++)
        cin>>pages[i];

    optimal_page_replacement();

    return 0;
}
/**
3
20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
*/
