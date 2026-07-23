EVALUATION SHEET HERE: https://github.com/Dsite42/minishell/blob/master/minishell_evalsheet.pdf

Mystery golbal variable is just the same signal as in minitalk (ack_recieved) but it rather used to interrupt current process run in minishell (for example by using ctrl+C)

PROJECT STRUCTURE SUGGESTED by Alina:
minishell/
├── Makefile
├── README.md
├── include/
│   ├── minishell.h
│   ├── parser.h
│   ├── executor.h
│   ├── env.h
│   ├── utils.h
│   └── libft.h
├── src/
│   ├── main.c
│   │
│   ├── parser/
│   │   └── parser.c
│   │
│   ├── executor/
│   │   ├── exec.c
│   │   └── signals.c
│   │
│   ├── env/
│   │   ├── env_init.c
│   │   ├── env_utils.c
│   │   └── env_update.c
│   │
│   └── utils/
│       ├── error.c
│       └── free.c
│
└── libft/   (optional, probably wont be added)

PROJECT STRUCTURE SUGGESTED by Samir:
<please provide if there are suggestions>

we can do the tree data structure but there is one issue in it. it is quite efficient but normally people who do bonus and also add && and || typically need the tree data structure, those who do the mantadory part only do it with the array or linked list. as you are doing the parsing you need to make the data structure, so if youre gonna do the tree im completely fine with that. its just a suggestion













Things to not forget before submition:
◦ norminette must be applied locally on 42 mashines;
◦ no idea how file header should look like for a group project