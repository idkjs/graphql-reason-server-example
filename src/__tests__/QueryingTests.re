open Jest;

open ExpectJs;

let () = {
  describe
    "Query.firstExample"
    (
      fun () =>
        testPromise
          "returns a single entry"
          (
            fun () =>
              GraphQL.run Schema.schema "{ firstExample { name, id } }" |>
              Js.Promise.then_ (
                fun execResult => Js.Promise.resolve (expect execResult |> toMatchSnapshot)
              )
          )
    );
  describe
    "Query.examples"
    (
      fun () =>
        testPromise
          "returns multiple entries"
          (
            fun () =>
              GraphQL.run Schema.schema "{ examples { name, id } }" |>
              Js.Promise.then_ (
                fun execResult => Js.Promise.resolve (expect execResult |> toMatchSnapshot)
              )
          )
    )
};
