## 📌 Flowchart of Personal Diary Application

```mermaid
flowchart TD

A([Start]) --> B[Display Main Menu]

B --> C[Take User Input (1-5)]

C -->|1| D[Add Entry]
C -->|2| E[View Entries]
C -->|3| F[Search Entry]
C -->|4| G[Delete Entry]
C -->|5| Z([Exit Program])

%% ADD ENTRY BRANCH
D --> D1[Open File in Append Mode]
D1 --> D2[Enter Date, Title, Content]
D2 --> D3[Save Entry to diary.txt]
D3 --> D4[Display 'Entry Added Successfully']
D4 --> B

%% VIEW ENTRIES BRANCH
E --> E1[Open File in Read Mode]
E1 --> E2[Display All Entries]
E2 --> B

%% SEARCH ENTRY BRANCH
F --> F1[Open File in Read Mode]
F1 --> F2[Enter Search Keyword]
F2 --> F3[Compare Keyword with Stored Records]
F3 -->|Match Found| F4[Display Result]
F3 -->|No Match| F5[Display 'No Entry Found']
F4 --> B
F5 --> B

%% DELETE ENTRY BRANCH
G --> G1[Open Original File in Read Mode]
G --> G2[Open Temporary File in Write Mode]
G1 --> G3[Enter Keyword]
G3 --> G4[Copy All Entries Except Match to Temp File]
G4 --> G5[Replace Old File with Updated File]
G5 --> G6[Display 'Entry Deleted Successfully']
G6 --> B

%% EXIT
Z --> H([End])
