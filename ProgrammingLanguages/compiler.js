var readline = require('readline');

var txmax = 100; // Length of identifier table
var nmax = 14; // Max number of digits in number
var al = 10; // Length of identifiers

var a = [];
var chars = [];
var rword = [];
var table = [];

const stdin = process.stdin;

// found this on github. This gets the entire stdin before continuing.
getStdin = () => {
	let ret = '';

	return new Promise(resolve => {
		if (stdin.isTTY) {
			resolve(ret);
		}

		stdin.setEncoding('utf8');

		stdin.on('readable', () => {
			let chunk;

			while ((chunk = stdin.read())) {
				ret += chunk;
			}
		});

		stdin.on('end', () => {
			resolve(ret);
        });
	});
};

// process.stdin.on('data', function(line){main(line + '')}); // reading and writting is asynchronous in nodejs so this reads the input and calls main when it is done
var currentLine = 0;
var infile, outfile, ch, sym, id, num, linlen, kk, line, errorFlag, linelen

function tableValue(name, kind) {
    return {
        name: name,
        kind: kind
    }
}
 
function error(num) {
    errorFlag = 1
    if (num == 1) {
        process.stdout.write('Use = instead of :=');
    } else if (num == 2) {
        process.stdout.write('= must be follwed by a number');
    } else if (num == 3) {
        process.stdout.write('Identifier must be followed by =');
    } else if (num == 4) {
        process.stdout.write('Const, Var, Procedure must be follwed by an identifier');
    } else if (num == 5) {
        process.stdout.write('Semicolon or comma missing');
    } else if (num == 6) {
        process.stdout.write('Incorrect symbol after procedure declaration');
    } else if (num == 7) {
        process.stdout.write('Statement expected');
    } else if (num == 8) {
        process.stdout.write('Incorrect symbol after statement part in block');
    } else if (num == 9) {
        process.stdout.write('Period expected');
    } else if (num == 10) {
        process.stdout.write('Semicolon between statements is missing');
    } else if (num == 11) {
        process.stdout.write('Undeclared identifier');
    } else if (num == 12) {
        process.stdout.write('Assignment to a constant or procedure is not allowed');
    } else if (num == 13) {
        process.stdout.write('Assignment operator := expected');
    } else if (num == 14) {
        process.stdout.write('Call must be followed by an identifier');
    } else if (num == 15) {
        process.stdout.write('Call of a constant or a variable is meaningless');
    } else if (num == 16) {
        process.stdout.write('Expected then');
    } else if (num == 17) {
        process.stdout.write('Expected semicolon or EOF');
    } else if (num == 18) {
        process.stdout.write('Expected DO');
    } else if (num == 19) {
        process.stdout.write('Incorrect symbol following statement');
    } else if (num == 20) {
        process.stdout.write('Expected relational operator');
    } else if (num == 21) {
        process.stdout.write('Expression must not contain a procedure identifier');
    } else if (num == 22) {
        process.stdout.write('Missing right parenthesis');
    } else if (num == 23) {
        process.stdout.write('Unexpected symbol');
    } else if (num == 24) {
        process.stdout.write('An expression cannot begin with this symbol');
    } else if (num == 25) {
        process.stdout.write('Constant or number expected');
    } else if (num == 26) {
        process.stdout.write('Number too large');
    } else {
        process.stdout.write('Unexpected error');
    }
    process.stdout.write('\n'); // newline to make program exit clean
    process.exit();
}

function getch() {
    if (whichChar == linelen) {
        whichChar = 0;
        line = infile[currentLine];
        linelen = line.length;
        currentLine = currentLine + 1;
        if (line) {
            process.stdout.write(line + '\n');
        }
    }
    if (linelen != 0) {
        ch = line[whichChar]
        whichChar += 1;
    }
}

function getsym() {
    while (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') {
        getch()
    }
    a = [];
    if (ch.match(/^[A-Z]$/i)) {
        var k = 0;
        while (true) {
            a.push(ch);
            getch();
            if (!ch.match(/^[A-Z]|[[0-9]$/i)) {
                break
            }
        }
        id = '';
        a.map(x => id = id + x);
        id = id.trim();
        var flag = 0;
        for (var i in rword) {
            if (rword[i] == id) {
                sym = rword[i];
                flag = 1;
            }
        }
        if (flag == 0) { // if sym is not a reserved word
            sym = 'ident'
        }
    } else if (ch.match(/^[0-9]$/i)) {
        var k = 0;
        num = 0;
        sym = 'number';
        while (true) {
            a.push(ch);
            k += 1;
            getch();
            if (!ch.match(/^[0-9]$/i)) {
                break;
            }
        }
        if (k > nmax) {
            error(30);
        } else {
            id = '';
            a.map(x => id = id + x);
            id = id.trim();
        }
    } else if (ch == ':') {
        getch()
        if (ch == '=') {
            sym = 'becomes';
            getch();
        } else {
            sym = "colon";
        }
    } else if (ch == '>') {
        getch()
        if (ch == '=') {
            sym = 'geq';
            getch();
        } else {
            sym = 'gtr';
        }
    } else if (ch == '<') {
        getch()
        if (ch == '=') {
            sym = 'leq';
            getch();
        } else if (ch == '>') {
            sym = 'neq';
            getch();
        } else {
            sym = 'lss';
        }
    } else {
        sym = ssym[ch];
        getch();
    }
}

function position(tx, k) {
    table[0] = tableValue(k, 'TEST');
    i = tx;
    while (table[i].name != k) {
        i = i - 1;
    }
    return i;
}

function enter(tx, k) {
    tx[0] += 1;
    while (table.length > tx[0]) {
        table.pop();
    }
    var x = tableValue(id, k);
    table.push(x);
}

function constdeclaration(tx) {
    if (sym == 'ident') {
        var tmp = id;
        getsym();
        if (sym == 'eql') {
            getsym();
            if (sym == 'number') {
                id = tmp;
                enter(tx, 'const');
                getsym();
            } else {
                error(2);
            }
        } else {
            error(3);
        }
    } else {
        error(4);
    }
}

function vardeclaration(tx) {
    if (sym == 'ident') {
        enter(tx, "variable");
        getsym();
    } else {
        error(4);
    }
}

function block(tableIndex) {
    tx = [];
    tx[0] = tableIndex;
    if (sym == 'CONST') {
        while (true) {
            getsym();
            constdeclaration(tx);
            if (sym != 'comma') {
                break;
            }
        }
        if (sym != 'semicolon') {
            error(10);
        }
        getsym();
    }

    if (sym == 'VAR') {
        while (true) {
            getsym();
            vardeclaration(tx);
            if (sym != "comma") {
                error(10);
            }
            getsym();
        }
    }

    while (sym == 'PROCEDURE') {
        getsym();
        if (sym == 'ident') {
            enter(tx, "procedure");
            getsym();
        } else {
            error(4);
        }
        if (sym != "semicolon") {
            error(10);
        }
        getsym();
        block(tx[0]);
        if (sym != 'semicolon') {
            error(10);
        }
        getsym();
    }
    statement(tx[0]);
}

function statement(tx) {
    if (sym == 'ident') {
        i = position(tx, id)
        if (i == 0) {
            error(11)
        } else if (table[i].kind != 'variable') {
            error(12)
        }
        getsym()
        if (sym != 'becomes') {
            error(13)
        }
        getsym()
        expression(tx)
    } else if (sym == 'CALL') {
        getsym()
        if (sym != 'ident') {
            error(14)
        }
        i = position(tx, id)
        if (i == 0) {
            error(11)
        }
        if (table[i].kind != 'procedure') {
            error(15)
        }
        getsym()
    } else if (sym == 'IF') {
        getsym()
        condition(tx)
        if (sym != 'THEN') {
            error(16)
        }
        getsym()
        statement(tx)
    } else if (sym == 'BEGIN'){
        while (true) {
            getsym()
            statement(tx)
            if (sym != 'semicolon') {
                break;
            }
        }
        if (sym != 'END') {
            error(17);
        }
        getsym();
    } else if (sym == 'WHILE') {
        getsym()
        condition(tx)
        if (sym != 'DO') {
            error(18)
        }
        getsym()
        statement(tx)
    }
}

function expression(tx) {
    if (sym == "plus" || sym == "minus") {
        getsym();
        term(tx);
    } else {
        term(tx)
    }
    while (sym == "plus" || sym == "minus"){
        getsym();
        term(tx);
    }
}

function term(tx){
    factor(tx);
    while ( sym == 'times' || sym == "slash") {
        getsym();
        factor(tx);
    }
}

function factor(tx) {
    if (sym == "ident") {
        i = position(tx, id)
        if (i == 0) {
            error(11);
        }
        getsym();
    } else if (sym == 'number') {
        getsym();
    } else if (sym == 'lparen') {
        getsym();
        expression(tx);
    }
    if (sym != "rparen") {
        error(22)
        getsym()
    } else {
        error(24)
    }
}

function condition(tx) {
    if (sym == 'ODD') {
        getsym()
        expression(tx)
    } else {
        expression(tx)
        if (!(sym in ["eql","neq","lss","leq","gtr","geq"])) {
            error(20);
        } else {
            getsym();
            expression(tx);
        }
    }
}
    


getStdin().then(function(input) {
    infile = input.split('\n');
    rword.push('BEGIN');
    rword.push('CALL');
    rword.push('CONST');
    rword.push('DO');
    rword.push('END');
    rword.push('IF');
    rword.push('ODD');
    rword.push('PROCEDURE');
    rword.push('THEN');
    rword.push('VAR');
    rword.push('WHILE');

    ssym = {'+' : "plus",
                '-' : "minus",
                '*' : "times",       
                '/' : "slash",
                '(' : "lparen",
                ')' : "rparen",
                '=' : "eql",
                ',' : "comma",
                '.' : "period",
                '#' : "neq",
                '<' : "lss",
                '>' : "gtr",
                '"' : "leq",
                '@' : "geq",
                ';' : "semicolon",
                ':' : "colon"}
                
    charcnt = 0;
    whichChar = 0;
    linelen = 0;
    ch = ' ';
    kk = al;                
    a = [];
    id= '     ';
    errorFlag = 0;
    table.push(0);
    sym = ' ';

    getsym();
    block(0);

    if (sym != "period") {
        error(9);
    }

    process.stdout.write(outfile);
    if (errorFlag == 0) {
        process.stdout.write('successful compilation');
    }
});