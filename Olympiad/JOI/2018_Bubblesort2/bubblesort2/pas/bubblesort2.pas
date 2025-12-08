unit bubblesort2;

interface

type
  array_of_longint = array of longint;

function count_scans(A, X, V: array_of_longint): array_of_longint;

implementation


function count_scans(A, X, V: array_of_longint): array_of_longint;
var
  Q, j: longint;
  answer: array of longint;
begin
  Q := length(X);
  setlength(answer, Q);
  for j := 0 to Q - 1 do begin
    answer[j] := X[j];
  end;
  exit(answer);
end;


end.
