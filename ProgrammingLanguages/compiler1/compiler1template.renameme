var readline = require('readline');

//disables console.log function if debug is not on
if (!process.argv.includes('debug')) {
    console.log = function() {};
}

console.log('setting up');
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
var infile, outfile, ch, sym, id, num, linlen, line, errorFlag, linelen

function tableValue(name, kind) {
    console.log('TABLEVALUE: Creating new tablevalue with name = ' + name + ' kind = ' + kind);
    return {
        name: name,
        kind: kind
    }
}
 
function error(num) {
    console.log('ERROR: throwing error ' + num);
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
    console.log('getch: getting ch whichchar ' + whichChar + ' linelen ' + linelen + ' currentline ' + currentLine);
    if (whichChar == linelen) {
        whichChar = 0;
        line = infile[currentLine];
        if (line == undefined) {
            return '';
        }
        if (line.length == 0) {
            process.stdout.write('\n');
            currentLine = currentLine + 1;
            line = infile[currentLine];
        }
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
    console.log('getch: ' + ch);
    return ch;
}

function getsym() {
    console.log('getsym: getting sym');
    while (ch == ' ' || ch == '\n' || ch == '\r' || ch == '') {
        console.log('getsym: getch 1')
        getch()
    }
    a = [];
    console.log('getsym: found character: ' + ch);
    if (ch.match(/^[A-Z]$/i)) {
        console.log('getsym: character \'' + ch + '\' is a letter');
        var k = 0;
        while (true) {
            console.log('getsym: is looping until a non alphanumeric charater is found');
            a.push(ch);
            console.log('getsym: getch 2');
            getch();
            if (!ch.match(/^[A-Z]|[0-9]$/i)) {
                console.log('getsym: loop completed');
                break
            }
        }
        console.log('getsym: mapping characters to a string');
        id = '';
        a.map(x => id = id + x);
        id = id.trim();
        console.log('getsym: found \'' + id + '\'');
        var flag = 0;
        console.log('getsym: checking if reserved word');
        for (var i in rword) {
            if (rword[i] == id) {
                console.log('getsym: is reserver word \'' + rword[i] + '\'');
                sym = rword[i];
                flag = 1;
            }
        }
        if (flag == 0) { // if sym is not a reserved word
            console.log('getsym: sym is ident');
            sym = 'ident'
        }
    } else if (ch.match(/^[0-9]+$/i)) {
        console.log('getsym: is 0-9')
        var k = 0;
        num = 0;
        console.log('getsym: sym = number');
        sym = 'number';
        while (true) {
            a.push(ch);
            console.log('getsym: building a string: ' + a);
            k += 1;
            console.log('getsym: getch 3');
            getch();
            if (!ch.match(/^[0-9]+$/i)) {
                console.log('getsym: not a number breaking loop');
                break;
            }
        }
        id = '';
        a.map(x => id = id + x);
        id = id.trim();
        console.log('getsym: number ' + id);
    } else if (ch == ':') {
        console.log('getsym: getch 4');
        getch()
        if (ch == '=') {
            console.log('getsym: sym is becomes');
            sym = 'becomes';
            console.log('getsym: getch 5');
            getch();
        } else {
            console.log('getsym: sym is colon');
            sym = "colon";
        }
    } else if (ch == '>') {
        console.log('getsym: running >')
        console.log('getsym: getch 6');
        getch()
        if (ch == '=') {
            sym = 'geq';
            console.log('getsym: getch 7');
            getch();
        } else {
            sym = 'gtr';
        }
    } else if (ch == '<') {
        console.log('getsym: running <')
        console.log('getsym: getch 8');
        getch()
        if (ch == '=') {
            sym = 'leq';
            console.log('getsym: getch 9');
            getch();
        } else if (ch == '>') {
            sym = 'neq';
            console.log('getsym: getch 10');
            getch();
        } else {
            sym = 'lss';
        }
    } else {
        console.log('getsym: sym = ' + ssym[ch])
        sym = ssym[ch];
        console.log('getsym: getch 11');
        getch();
    }
}

function position(tx, k) {
    console.log('position: tableindex = ' + tx + ' k = ' + k);
    table[0] = tableValue(k, 'TEST');
    console.log('position: table[0] = ' + table[0])
    i = tx;
    while (table[i].name != k) {
        i = i - 1;
    }
    return i;
}

function enter(tx, k) {
    console.log('enter: tableindex = ' + tx + ' k = ' + k);
    tx[0] += 1;
    while (table.length > tx[0]) {
        table.pop();
    }
    var x = tableValue(id, k);
    console.log('enter: tablevalue = ' + x)
    table.push(x);
}

function constdeclaration(tx) {
    console.log('constdeclaration: tx = ' + tx);
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
    console.log('vardeclaration: tx = ' + tx);
    if (sym == 'ident') {
        enter(tx, "variable");
        getsym();
    } else {
        error(4);
    }
}

function block(tableIndex) {
    console.log('block: tableindex = ' + tableIndex);
    tx = [1];
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
                break;
            }
        }

        if (sym != 'semicolon') {
            error(10);
        }
        getsym();
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
    console.log('statement: tx = ' + tx)
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
    console.log('expression: tx = ' + tx);
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
    console.log('term: tx = ' + tx)
    factor(tx);
    while ( sym == 'times' || sym == "slash") {
        getsym();
        factor(tx);
    }
}

function factor(tx) {
    console.log('factor: tx = ' + tx);
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
    
        if (sym != "rparen") {
            error(22)
        }
        getsym()
    } else {
        error(24)
    }
}

function condition(tx) {
    console.log('condition: tx = ' + tx)
    if (sym == 'ODD') {
        getsym()
        expression(tx)
    } else {
        expression(tx)
        if (!(["eql","neq","lss","leq","gtr","geq"].includes(sym))) {
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

    // process.stdout.write(outfile);
    if (errorFlag == 0) {
        process.stdout.write('Successful compilation!\n');
    }
});