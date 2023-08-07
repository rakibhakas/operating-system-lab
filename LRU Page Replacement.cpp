#include <bits/stdc++.h>
using namespace std;

const int N=100005;

int n;
int frame_size;
int pages[N];
int last_use[N];

void lru_page_replacement(void)
{
    vector<int>frames;
    int i,j,k,page_faults,index,optimal;

    page_faults = 0;
    for(i=0; i<n; i++)
    {
        for(k=0; k<frames.size(); k++)
        {
            if(frames[k] == pages[i]) break;
        }

        if(k == frames.size())
        {
            if(frames.size() == frame_size)
            {
                optimal = 0;
                index = n + 1;

                for(k=0; k<frames.size(); k++)
                {
                    j = frames[k];
                    if(last_use[j] < index)
                    {
                        optimal = k;
                        index = last_use[j];
                    }
                }

                index = pages[i];
                last_use[index] = i;
                frames[optimal] = pages[i];
            }
            else
            {
                index = pages[i];
                last_use[index] = i;
                frames.push_back(pages[i]);
            }

            page_faults++;
            cout<<"Reference to page "<<pages[i]<<" caused a page fault\n";
        }
        else
        {
            index = pages[i];
            last_use[index] = i;
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

    lru_page_replacement();

    return 0;
}
/**
3
20
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1
*/
