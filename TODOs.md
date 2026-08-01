EVALUATION SHEET HERE: https://github.com/Dsite42/minishell/blob/master/minishell_evalsheet.pdf

Mystery golbal variable is just the same signal as in minitalk (ack_recieved) but it rather used to interrupt current process run in minishell (for example by using ctrl+C)

TODO: Naming should be discussed before its too late! o_0

LIST OF COMMANDS TO IMPLEMENT:
◦ echo with option -n (including variables inside '' and "");
◦ cd with only a relative or absolute path;
◦ pwd with no options;
◦ export with no options;
◦ unset with no options;
◦ env with no options or arguments;
◦ exit with no options;

CURRENT PROJECT STRUCTURE:
minishell/
├── Makefile
├── README.md
├── minishell.h
├── src/
│   ├── main.c
│   ├── parse/
│   │   └── ft_parse.c
│   ├── executor/
│   │   ├── execute.c
│   │   └── signals.c
│   ├── env/
│   │   ├── env_init.c
│   │   ├── env_utils.c
│   │   └── env_update.c
│   └── utils/
│       ├── error.c
│       └── free.c
└── libft/   (optional, probably wont be added)
		└── libft.h

PROJECT STRUCTURE SUGGESTED by Samir:
<please provide if there are suggestions>

we can do the tree data structure but there is one issue in it. it is quite efficient but normally people who do bonus and also add && and || typically need the tree data structure, those who do the mantadory part only do it with the array or linked list. as you are doing the parsing you need to make the data structure, so if youre gonna do the tree im completely fine with that. its just a suggestion


Things to not forget before submition:
◦ norminette must be applied locally on 42 mashines;
◦ no idea how file header should look like for a group project