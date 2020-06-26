open Jest;

type body = {
  messages: array(string),
  page: int,
};

describe("Response for V2 format with valid body", () => {
  Expect.(
    V2.(
      test("toBe", () => {
        let headers = Js.Dict.empty();
        Js.Dict.set(headers, "headerName", "headerValue");
        let response =
          Response.make(
            ~cookies=[|"cookie1", "cookie2"|],
            ~headers,
            ~statusCode=200,
            ~body={
              messages: [|
                "Hello from Lambda!",
                "This is V2 response format",
              |],
              page: 1,
            },
            (),
          );
        
        expect(Js.Json.stringifyAny(response))
        |> toBe(
             Some(
               "{\"statusCode\":200,\"cookies\":[\"cookie1\",\"cookie2\"],\"headers\":{\"headerName\":\"headerValue\"},\"body\":\"{\\\"messages\\\":[\\\"Hello from Lambda!\\\",\\\"This is V2 response format\\\"],\\\"page\\\":1}\"}",
             ),
           );
      })
    )
  )
});

describe("Response for V2 format without body", () => {
  Expect.(
    V2.(
      test("toBe", () => {
        let headers = Js.Dict.empty();
        Js.Dict.set(headers, "headerName", "headerValue");
        let response =
          Response.make(
            ~cookies=[|"cookie1", "cookie2"|],
            ~headers,
            ~statusCode=200,
            (),
          );
        expect(Js.Json.stringifyAny(response))
        |> toBe(
             Some(
               "{\"statusCode\":200,\"cookies\":[\"cookie1\",\"cookie2\"],\"headers\":{\"headerName\":\"headerValue\"}}",
             ),
           );
      })
    )
  )
});
